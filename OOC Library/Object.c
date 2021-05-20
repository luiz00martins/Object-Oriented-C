
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <setjmp.h>
#include "Object.r"

/**
 * Notes: 
 *-When creating new names for primitives, prefer #define over typedef. Almost all of the mechanisms for primitives in macros
 * rely on their actual name. Each time a custom name is added, modifications on those are needed (see "typechecking" in "OOOCP.h"),
 * so add them sparringly.
 */

// Defines
#define MAX_BACKTRACE 1024
#define MAX_AUTOS MAX_BACKTRACE*16


// TODO: Create a new_static that releases memory at _returning.
// TODO: If you add a intermediate variable in returning, you can make it accept immediate values as well.
// TODO: There's a lot of repeated code in new, supercall and auto.
// TODO: Make the autos list dynamic.
// TODO: Implement a way to remove unnecessary castings of primitive types.
// TODO: Add copy function (and perhaps a deepcopy method).

// FIXME: You can make super class cycles. Check for this in create class.

/** START Helper functions **/
int _arrayPtrSize(void** ptr){
    int i;

    for (i = 0; ptr[i] != NULL; i++);
    i++;

    return i;
}
bool _hasFunc(void** ptr, void* func){
    int i;

    for (i = 0; ptr[i] != NULL; i++){
        if (ptr[i] == func){
            return true;
        }
    }

    return false;
}
method_hash hash(const unsigned char* str){
    method_hash hash = 5381;
    int c;

    while (c = *str++)
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */

    return hash;
}
/** END Helper functions**/
// SUPER KNOWS ABOUT BACKTRACE
/** Backtracing setup **/
struct backtrace{
    char* methodName[MAX_BACKTRACE];
    long long line[MAX_BACKTRACE];
    struct OOC_Class* class[MAX_BACKTRACE];
    char* file[MAX_BACKTRACE];
    // The number of allocated autos up to that backtrace layer.
    long long autoPrefixSum[MAX_BACKTRACE];
    // The current layer of calls, starting with 0 (top-1 is the previous)
    long long top;

    // Contains the addresses of all automatic objects, in order of creation.
    struct Object* autoAddresses[MAX_AUTOS];
    long long autoAddressesLen;
};
static struct backtrace OOC_backtrace;
/**----------**/

/** Stack setup **/
// The index and management of the stack is guided together with the backtrace.
struct stack{

};
static struct backtrace OOC_backtrace;
/**----------**/

/** START Static functions **/
#if __unix__
// warning: some sketchy code ahead.
sigjmp_buf jumpBuffer;
struct sigaction defact;
// This dummy handler jumps to the "false" response.
void segHandler(int sig){
    siglongjmp(jumpBuffer, true);
}
struct sigaction sigact = {.sa_handler = segHandler};
// Note: This function may return false if the class is corrupted.
bool OOC_isClass(pointer ptr, long long line, char* file){
    if (!ptr){
        OOC_fatalError("NULL pointer passed", line, file);
    }
    // Setting action of segmentation fault to go to segHandler.
    sigaction(SIGSEGV, &sigact, &defact);

    // Sets jmp for failure.
    // This jump happens in case trying to access the key results in segmentation fault.
    if(sigsetjmp(jumpBuffer, 1)){
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }

    // Verifying key (possible segmentation fault)
    if(((struct OOC_Class*)ptr)->key != OOC_CLASS_KEY){
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }
    else {
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return true;
    }
}
#elif (_WIN32 || _WIN64)
jmp_buf jumpBuffer;
void dummyHandler(int sig){
    longjmp(jumpBuffer, true);
}
bool isClass(const void* ptr){
    if (!ptr){
        OOC_fatalError("NULL pointer passed");
    }
    signal(SIGSEGV, dummyHandler);

    if(setjmp(jumpBuffer)){
        signal(SIGSEGV, SIG_DFL);
        return false;
    }

    if(((struct Class*)ptr)->_ctor != _ctor){
        signal(SIGSEGV, SIG_DFL);
        return false;
    }

    signal(SIGSEGV, SIG_DFL);
    return true;
}
#endif
bool OOC_isObject(pointer ptr, long long line, char* file){
    if (!ptr){
        OOC_fatalError("NULL pointer passed", line, file);
    }
    // Setting action of segmentation fault to go to segHandler.
    sigaction(SIGSEGV, &sigact, &defact);

    // Sets jmp for failure.
    // This jump happens in case trying to access the key results in segmentation fault.
    if(sigsetjmp(jumpBuffer, 1)){
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }

    // Verifying key (possible segmentation fault)
    if(((struct Object*)ptr)->class->key != OOC_CLASS_KEY){
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }
    else {
        // Resetting segmentation action.
        sigaction(SIGSEGV, &defact, NULL);
        return true;
    }
}
bool OOC_ofClass(pointer self, struct OOC_Class* class, long long line, char* file){
    // TODO: Change all printfs for its own functions when Exceptions are added
    // Verifying if the variable self is an object
    if(!OOC_isObject(self, line, file)){
        OOC_fatalError("pointer is not an Object", line, file);
    }
    // Verifying if the variable class is an class
    if(!OOC_isClass(class, line, file)){
        OOC_fatalError("pointer is not a class", line, file);
    }

    struct OOC_Class* selfClass = ((struct Object*)self)->class;

    if (selfClass == class)
        return true;
    else
        return false;
}
/**
 * Returns a boolean for if the object {@code self} is an instance of {@code class}
 *
 * @param self Object
 * @param class Class
 * @return {@code true} if the object {@code self} is of the class {@code class}, {@code false}
 */
bool OOC_instanceOfClass(pointer self, struct OOC_Class* class, long long line, char* file){
    // Note: This bit of code assumes that "ofClass" already checks 
    // if "self" is an object and if "class" is a class.
    if (OOC_ofClass(self, class, line, file) || class == Object()){
        return true;
    }
    else {
        struct OOC_Class* selfClass = ((struct Object*)self)->class;

        printf("%s\n", selfClass->name);
        fflush(stdout);
        // Checking all the supers until it reaches "Class()".
        while(selfClass != Object()){
            if(selfClass == class){
                return true;
            }
            else{
                selfClass = selfClass->super;
            }
        }
        return false;
    }
}
pointer OOC_cast(struct OOC_Class* class, pointer self, long long line, char* file){
    if (!OOC_instanceOfClass(self, class, line, file)) {
        if(OOC_isObject(self, line, file)){
            snprintf(_OOC_error_message, _OOC_MAX_ERROR_MESSAGE_SIZE, "Cannnot cast type %s to %s", ((struct Object*)self)->class->name, class->name);
            OOC_fatalError(_OOC_error_message, line, file);
        } 
        else {
            OOC_fatalError("pointer is not an Object", line, file);
        }
    }
    return self;
}
/**
 * Returns the superclass of a class
 * @param self Class
 * @return superclass
 */
struct OOC_Class* OOC_super(struct OOC_Class* class, long long line, char* file){
    if(!OOC_isClass(class, line, file)){
        OOC_fatalError("pointer is not a class", line, file);
    }

    return class->super;
}
struct OOC_Class* OOC_getClass(pointer self, long long line, char* file){
    if(!OOC_isObject(self, line, file)){
        OOC_fatalError("pointer is not an Object", line, file);
    }
    return ((struct Object*)self)->class;
}
int OOC_sizeOf(pointer self, long long line, char* file){
    struct OOC_Class* selfClass = OOC_getClass(self, line, file);

    return selfClass->size;
}
static inline void _OOC_backtraceUp(char* methodName, long long line, char* file, struct OOC_Class* class){
    OOC_backtrace.methodName[OOC_backtrace.top] = methodName;
    OOC_backtrace.line[OOC_backtrace.top] = line;
    OOC_backtrace.class[OOC_backtrace.top] = class;
    OOC_backtrace.file[OOC_backtrace.top] = file;
    OOC_backtrace.autoPrefixSum[OOC_backtrace.top] = OOC_backtrace.autoAddressesLen;
    OOC_backtrace.top++;
}
static inline void _OOC_backtraceDown(){
    OOC_backtrace.top--;
}
static inline void _OOC_clearAutos(){
    int i;
    for(i = OOC_backtrace.autoAddressesLen; OOC_backtrace.autoAddressesLen > OOC_backtrace.autoPrefixSum[OOC_backtrace.top]; OOC_backtrace.autoAddressesLen){
        OOC_backtrace.autoAddressesLen--;
        delete(OOC_backtrace.autoAddresses[OOC_backtrace.autoAddressesLen]);
    }
}    
static inline method _OOC_findMethod(char* methodName, struct OOC_Class* class, long long line, char* file){
    method_hash key = hash((unsigned char*)methodName);
    
    method mth = NULL;
    int i;
    for (i = 0; i < class->methodListLen; i++){
        if (class->methodKeys[i] == key){
            mth = class->methods[i];
            break;
        }
    }
    if (mth == NULL){
        snprintf(_OOC_error_message, _OOC_MAX_ERROR_MESSAGE_SIZE, "No method \'%s\' in class %s", methodName, class->name);
        OOC_fatalError(_OOC_error_message, line, file);
    }
    
    return mth;
}
pointer OOC_callSuperMethod(long long line, char* file, pointer self, ...){
    if (!OOC_isObject(self, line, file)){
        OOC_fatalError("pointer is not an Object", line, file);
    }

    struct OOC_Class* class = OOC_backtrace.class[OOC_backtrace.top-1];
    char* methodName = OOC_backtrace.methodName[OOC_backtrace.top-1];

    struct OOC_Class* superClass = OOC_super(class, line, file);

    method mth = _OOC_findMethod(methodName, superClass, line, file);

    // Setting up backtrace.
    _OOC_backtraceUp(methodName, line, file, superClass);

    va_list args;
    va_start(args, self);
    void* result = mth(self, &args);
    va_end(args);

    // Moving back backtrace.
    _OOC_backtraceDown();
    _OOC_clearAutos();

    return result;
}
pointer OOC_callMethod(unsigned char* methodName, long long line, char* file, pointer self, ...){
    method_hash key = hash(methodName);

    struct OOC_Class* class = OOC_getClass(self, line, file);

    method mth = _OOC_findMethod(methodName, class, line, file);

    // Setting up backtrace.
    _OOC_backtraceUp(methodName, line, file, class);

    va_list args;
    va_start(args, self);
    void* result = mth(self, &args);
    va_end(args);

    // Moving back backtrace.
    _OOC_backtraceDown();
    _OOC_clearAutos();

    return result;
}
pointer OOC_newClass(struct OOC_Class* superClass, char* name, size_t size, long long line, char* file, ...){
    if (!OOC_isClass(superClass, line, file)){
        OOC_fatalError("pointer is not a class", line, file);
    }
    struct OOC_Class* super = superClass;

    struct OOC_Class* class = malloc(sizeof(struct OOC_Class));
    assert(class);

    // Setting up and allocating new class
    class->super = superClass;
    class->name = malloc(sizeof(char) * strlen(name));
    strcpy(class->name, name);
    class->size = size;
    class->abstract = false;
    class->methodListLen = superClass->methodListLen;
    class->methodKeys = malloc(sizeof(method_hash) * superClass->methodListLen);
    class->methods = malloc(sizeof(method) * superClass->methodListLen);
    class->key = OOC_CLASS_KEY;

    // Copying super methods
    int i;
    for (i = 0; i < class->methodListLen; i++){
        class->methodKeys[i] = super->methodKeys[i];
        class->methods[i] = super->methods[i];
    }

    // Method definition and overload.
    char* methodName;
    method_hash key;
    method function;
    bool overloaded_flag;
    va_list args;

    va_start(args, file);
    while((methodName = va_arg(args, char*))){
        key = hash((unsigned char*)methodName);
        function = va_arg(args, method);
        // Checking if the method is already present to be overloaded.
        overloaded_flag = false;
        for (i = 0; i < class->methodListLen; i++){
            if (class->methodKeys[i] == key){
                class->methods[i] = function;
                overloaded_flag = true;
                break;
            }
        }
        if (!overloaded_flag){
            // Adding one len for the new method.
            class->methodListLen++;
            // Allocating more space for the new method.
            method_hash* newMethodKeys = malloc(sizeof(method_hash) * class->methodListLen);
            method* newMethods = malloc(sizeof(method) * class->methodListLen);
            // Copying old methods.
            memcpy(newMethodKeys, class->methodKeys, (sizeof(method_hash) * (class->methodListLen-1)));
            memcpy(newMethods, class->methods, (sizeof(method) * (class->methodListLen-1)));
            // Deleting old methods.
            free(class->methodKeys);
            free(class->methods);
            // Passing new (longer) list.
            class->methodKeys = newMethodKeys;
            class->methods = newMethods;
            // Adding new method.
            class->methodKeys[class->methodListLen-1] = key;
            class->methods[class->methodListLen-1] = function;
        }
    }
    va_end(args);

    // Verifying if the class is abstract (has an abstract method declared)
    for (i = 0; i < class->methodListLen; i++){
        if (class->methods[i] == OOC_abstract){
            class->abstract = true;
            break;
        }
    }

    return class;
}
pointer OOC_new(pointer type, long long line, char* file, ...){
    if (!OOC_isClass(type, line, file)){
        OOC_fatalError("pointer is not a class", line, file);
    }
    else if (((struct OOC_Class*)type)->abstract) {
        OOC_fatalError("Cannot instantiate abstract class", line, file);
    }
    struct OOC_Class* class = (struct OOC_Class*)type;
    struct Object* object;

    // Allocating space for new object.
    object = malloc(class->size);
    assert(object);

    // Setting up class.
    object->class = class;

    // Finding constructor
    method mth = _OOC_findMethod("ctor", class, line, file);
    
    // Setting up backtrace.
    _OOC_backtraceUp("ctor", line, file, class);

    va_list args;
    va_start(args, file);
    mth((void*)object, &args);
    va_end(args);

    // Moving back backtrace.
    _OOC_backtraceDown();
    _OOC_clearAutos();

    return object;
}
pointer OOC_delete(pointer self, long long line, char* file){
    dtor(cast(Object, self));
    free((void*)_OOC_returning_buffer);
    return self;
}
pointer OOC_automatic(pointer type, long long line, char* file, ...){
    if (!OOC_isClass(type, line, file)){
        OOC_fatalError("pointer is not a class", line, file);
    }
    else if (((struct OOC_Class*)type)->abstract) {
        OOC_fatalError("Cannot instantiate abstract class", line, file);
    }
    struct OOC_Class* class = (struct OOC_Class*)type;
    struct Object* object;

    // Allocating space for new object.
    object = malloc(class->size);
    assert(object);

    // Setting up class.
    object->class = class;

    // Finding constructor
    method mth = _OOC_findMethod("ctor", class, line, file);
    
    // Setting up backtrace.
    _OOC_backtraceUp("ctor", line, file, class);

    va_list args;
    va_start(args, file);
    mth((void*)object, &args);
    va_end(args);

    // Moving back backtrace.
    _OOC_backtraceDown();
    _OOC_clearAutos();

    // Adding automatic.
    OOC_backtrace.autoAddresses[OOC_backtrace.autoAddressesLen] = object;
    OOC_backtrace.autoAddressesLen++;

    return object;
}
struct Object* OOC_copy(pointer self, long long line, char* file){
    cast(Object, self);

    struct Object* newObj = malloc(OOC_sizeOf(self, line, file));

    memcpy(newObj, self, OOC_sizeOf(self, line, file));

    return newObj;
}
pointer OOC_abstract(pointer self, va_list *args){
    cast(Object, self);

    OOC_fatalError("Abstract method called", 0, NULL);

    return NULL;
}
void OOC_copyTo(pointer from, pointer to, long long line, char* file){
    cast(Object, from);
    cast(Object, to);

    assert(OOC_sizeOf(from, line, file) == OOC_sizeOf(to, line, file));

    dtor(to);
    
    memcpy(to, from, OOC_sizeOf(from, line, file));
}
pointer OOC_printBacktrace(){
    OOC_backtrace.top--;
    for(;OOC_backtrace.top >= 0; OOC_backtrace.top--){
        printf("\tin file \'%s\', at method call %s.%s, line %Li\n"
            , OOC_backtrace.file[OOC_backtrace.top]
            , OOC_backtrace.class[OOC_backtrace.top]->name
            , OOC_backtrace.methodName[OOC_backtrace.top]
            , OOC_backtrace.line[OOC_backtrace.top]);
    }
}

pointer OOC_fatalError(char* message, long long line, char* file){
    printf("\n\nError");
    if (file) printf(" in file \'%s\'", file);
    if (line) printf(", line %Li", line);
    if(message) printf(": %s", message);
    printf("\n");
    OOC_printBacktrace();
    fflush(stdout);
    assert(0);
}
/** END Static functions **/


/* START Object function definitions */
static pointer Object_ctor(pointer self, va_list* args){
    returning(Object, self);
}

static pointer Object_dtor(pointer self, va_list* args){
    returning(Object, self);
}

static pointer Object_equals(pointer self, va_list* args){
    param(Object, obj);
    
    bool returned = true;
    if(self == obj)
        returning(bool, returned);

    returned = false;
    returning(bool, returned);
}

static pointer Object_deepcopy(pointer self, va_list* args){
    returning(Object, self);
}
/* END Object function definitions */

static pointer _class = NULL;

pointer Object(){
    if (!_class){
        // Starting up backtrace
        OOC_backtrace.top = 0;
        OOC_backtrace.autoAddressesLen = 0;
        // We set up the data with a dummy, since "class" is const.
        struct OOC_Class* dummy = malloc(sizeof(struct OOC_Class));

        // Setting up class.
        dummy->name = "Object";
        dummy->super = dummy;
        dummy->size = sizeof(struct Object);
        dummy->abstract = false;
        dummy->methodListLen = 4;
        dummy->key = OOC_CLASS_KEY;

        // Setting up methods.
        dummy->methodKeys = malloc(sizeof(method_hash) * dummy->methodListLen);
        dummy->methods = malloc(sizeof(method) * dummy->methodListLen);

        // Storing functions and their hashes.
        // NOTE: Hashes are used as keys to speed up function retrieval,
        // as comparing ints is faster than strings,
        // but the list is not currently implemented as a hash table.
        // TODO [Maybe]: Implement these lists as hash tables.
        dummy->methodKeys[0] = hash("ctor");
        dummy->methods[0] = Object_ctor;
        dummy->methodKeys[1] = hash("dtor");
        dummy->methods[1] = Object_dtor;
        dummy->methodKeys[2] = hash("equals");
        dummy->methods[2] = Object_equals;
        dummy->methodKeys[3] = hash("deepcopy");
        dummy->methods[3] = Object_deepcopy;

        _class = dummy;

    }
    return _class;
}






