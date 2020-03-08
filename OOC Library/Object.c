
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include <signal.h>
#include <setjmp.h>
#include "Object.h"
#include "Object.r"

// TODO: Create a static_new with a starting and end function that destroys statically created items bewteen the start and end function
// TODO: Create a print function with specifier %o
// TODO: Add copy function (and perhaps a deepcopy function) with error message "function not defined"
// TODO: Implement get and set as a keyword, to get super variables

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
/** END Helper functions **/


/** START Static functions **/
void* new(const void* self, ...){
    const struct Class* class = cast(Class(), self);
    struct Object* object;
    va_list args;

    assert(class->size);
    object = malloc(class->size);
    assert(object);

    object->class = class;

    va_start(args, self);
    class->this_ctor(object, &args);
    va_end(args);

    if(ofClass(object, Object()) && class->abstract){
        printf("\nERROR: Cannot instantiate abstract object\n");
        fflush(stdout);
        assert(0);
    }

    return object;
}
void delete(void* self){
    free(dtor(cast(Class(), self)));
}
struct Object* copy(const void* self){
    cast(Object(), self /* Can only copy objects */);

    struct Object* newObj = malloc(sizeOf(self));

    memcpy(newObj, self, sizeOf(self));

    return newObj;
}
const struct Class* getClass(const void* self){
    if (!self){
        printf("\nERROR: NULL pointer passed\n");
        fflush(stdout);
        assert(0);
    }
    return *((const struct Class**)self);
}
int sizeOf(const void* self){
    const struct Class* selfClass = getClass(self);
    assert(self);

    return selfClass->size;
}
#if __unix__
sigjmp_buf jumpBuffer;
struct sigaction defact;
void dummyHandler(int sig){
    siglongjmp(jumpBuffer, true);
}
struct sigaction sigact = {.sa_handler = dummyHandler};
bool isAClass(const void* ptr){
    if(!ptr){
        printf("\nERROR: NULL pointer passed\n");
        fflush(stdout);
        assert(0);
    }
    sigaction(SIGSEGV, &sigact, &defact);

    if(sigsetjmp(jumpBuffer, 1)){
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }

    if(((struct Class*)ptr)->_ctor != _ctor){
        return false;
    }

    return true;
}
bool isAnObject(const void* ptr){
    if(!ptr){
        printf("\nERROR: NULL pointer passed\n");
        fflush(stdout);
        assert(0);
    }

    sigaction(SIGSEGV, &sigact, &defact);

    if(sigsetjmp(jumpBuffer, 1)){
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }

    const struct Class* selfClass = getClass(ptr);

    // In case can't even access seflClass->_ctor


    if(!selfClass || selfClass->_ctor != _ctor){
        sigaction(SIGSEGV, &defact, NULL);
        return false;
    }

    sigaction(SIGSEGV, &defact, NULL);
    return true;
}
#elif (_WIN32 || _WIN64)
jmp_buf jumpBuffer;
void dummyHandler(int sig){
    longjmp(jumpBuffer, true);
}
bool isAClass(const void* ptr){
    if(!ptr){
        printf("\nERROR: NULL pointer passed\n");
        fflush(stdout);
        assert(0);
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
bool isAnObject(const void* ptr){
    if(!ptr){
        printf("\nERROR: NULL pointer passed\n");
        fflush(stdout);
        assert(0);
    }
    signal(SIGSEGV, dummyHandler);

    // In case can't even access seflClass->_ctor
    if(setjmp(jumpBuffer)){
        signal(SIGSEGV, SIG_DFL);
        return false;
    }

    const struct Class* selfClass = getClass(ptr);

    if(!selfClass || selfClass->_ctor != _ctor){
    signal(SIGSEGV, SIG_DFL);
        return false;
    }

    signal(SIGSEGV, SIG_DFL);
    return true;
}
#endif
bool isClass(const void* self, const struct Class* class){
    // TODO: Change all printfs for its own functions when Exceptions are added
    // Verifying if the variable self is an object
    if(!isAnObject(self)){
        printf("\nERROR: Non-object pointer used where object was expected\n");
        fflush(stdout);
        assert(0);
    }
    // Verifying if the variable class is an class
    if(!isAClass(class)){
        printf("\nERROR: Non-class pointer used where class was expected\n");
        fflush(stdout);
        assert(0);
    }

    const struct Class* selfClass = getClass(self);

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
bool ofClass(const void* self, const struct Class* class){
    if (isClass(self, class) || class == Class()){
        return true;
    }
    else {
        const struct Class* selfSuper = getClass(self);

        while(selfSuper != Class()){
            if(selfSuper == class){
                return true;
            }
            else{
                selfSuper = super(selfSuper);
            }
        }
        return false;
    }
}
void* cast(const struct Class* class, const void* self){
    assert(ofClass(self, class) /* Self cannot cast into class. Go one level up on debugger to see a specific error mesage */);
    return self;
}
/**
 * Returns the superclass of a class
 * @param self Class
 * @return superclass
 */
const void* super(const void* self){
    const struct Class* selfClass = cast(Class(), self);

    return selfClass->super;
}
void* abstract(const void* self, va_list *args){
    cast(Class(), self);

    printf("\nERROR: Abstract method called\n");
    fflush(stdout);
    assert(0 /* Cannot call abstract function */);

    return NULL;
}
void copyTo(void* from, void* to){
    cast(Object(), from);
    cast(Object(), to);

    assert(sizeOf(from) == sizeOf(to));

    dtor(to);

    memcpy(to, from, sizeOf(from));
}
void* _returning(void* ptr, int size){
    if(!_buffer){
        _buffer = malloc(sizeof(long long));
    }

    memcpy(_buffer, ptr, size);

    return _buffer;
}
/** END Static functions **/

build_caller_funcs(ctor, dtor, equals, deepcopy)

/** START Caller functions **/
single_build_func(Object, ctor, (va_list*, nargs))

single_build_func(Object, dtor, ())

single_build_func(Object, deepcopy, ())

single_build_func(Object, equals, (void*, obj))


/* START Caller functions */


/* END Caller functions */

/* START Class function definitions */
void* Class_ctor(void* self, va_list* args){
    struct Class* classPtr = cast(Class(), self);

    // TODO: (After implementing object as abstract)
    // if it's abstract, it has to be a sub of an abstract
    //if(isClass(self, Class())){
    //
    //}

    classPtr->name = va_arg(*args, char*);
    classPtr->super = va_arg(*args, struct Class*);
    classPtr->size = va_arg(*args, size_t);
    classPtr->dataGet = malloc(sizeof(void*));
    classPtr->dataOffsets = malloc(sizeof(int));
    classPtr->dataSizes = malloc(sizeof(int));
    classPtr->abstract = false;

    cast(Class(), classPtr->super);

    classPtr->dataGet[0] = NULL;
    classPtr->dataOffsets[0] = NULL;
    classPtr->dataSizes[0] = NULL;

    /* Copying functions */
    const size_t offset = offsetof(struct Class, _ctor);
    // NOTE: If something goes to shit, note that in the book's code sizeOf(classPtr->object) is actually sizeOf(classPtr->super), don't know why tho
    memcpy((char*) self + offset, (char*) classPtr->super + offset
            , sizeOf(classPtr->super) - offset);

    typedef void (* voidf) (); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    // Setting dynamic caller pointers
    // NOTE: Perhaps this is needed (probably not)
    classPtr->_ctor = _ctor;
    classPtr->caller_ctor = caller_Object_ctor;
    classPtr->_dtor = _dtor;
    classPtr->caller_dtor = caller_Object_dtor;
    classPtr->_equals = _equals;
    classPtr->caller_equals = caller_Object_equals;
    classPtr->_deepcopy = _deepcopy;
    classPtr->caller_deepcopy = caller_Object_deepcopy;

    va_copy(funcArgs, *args);
    /* Function overload function */
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        // Add system to notice non implemented functions

        if (selector == _ctor){
            classPtr->this_ctor = function;
        }
        else if (selector == _dtor) {
            if(!ofClass(&self, Object())){
                assert(0 /* Class generetors shouldn't implement dtor, as classes are permanent */);
            }
            classPtr->this_dtor = function;
        }
        else if (selector == _equals) {
            if(!ofClass(&self, Object())){
                assert(0 /* Class generetors shouldn't implement equals, as classes are unique */);
            }
            classPtr->this_equals = function;
        }
        else if (selector == _deepcopy) {
            if(!ofClass(&self, Object())){
                assert(0 /* Class generetors shouldn't implement deepcopy, as classes are unique */);
            }
            classPtr->this_deepcopy = function;
        }
    }
    va_end(funcArgs);

    // Verifying if the class is abstract (has an abstract method declared)
    if (classPtr->this_ctor == abstract ||
            classPtr->this_dtor == abstract ||
            classPtr->this_equals == abstract ||
            classPtr->this_deepcopy == abstract){

        classPtr->abstract = true;
    }

    return self;
}

/* END Class function definitions */

/* START Object function definitions */
void* Object_ctor(void* self, va_list* args){
    return cast(Object(), self);
}

void* Object_dtor(void* self){
    return cast(Object(), self);
}

void* Object_equals(void* self, void* obj){
    cast(Object(), self);
    cast(Object(), obj);

    bool returned = true;
    if(self == obj)
        return returning(returned);

    returned = false;
    return returning(returned);
}

void* Object_deepcopy(void* self){
    return cast(Object(), self);
}
/* END Object function definitions */

/* START Class Description */
const struct Class class = {
        .object = &class,
        .name = "Class",
        .super = &class,
        .size = sizeof(struct Class),
        .dataGet = NULL,
        .dataOffsets = NULL,
        .dataSizes = NULL,
        .abstract = false,

        ._ctor = _ctor,
        .caller_ctor = caller_Object_ctor,
        .this_ctor = Class_ctor,
        ._dtor = _dtor,
        .caller_dtor = caller_Object_dtor,
        .this_dtor = abstract,
        ._equals = _equals,
        .caller_equals = caller_Object_equals,
        .this_equals = abstract,
        ._deepcopy = _deepcopy,
        .caller_deepcopy = caller_Object_dtor,
        .this_deepcopy = abstract,
};

const void* const Class(){
    return &class;
}
/* END Class Description */

/* START Object Description */
// TODO: Make object abstract
const struct Class object = {
        .object = &class,
        .name = "Object",
        .super = &class,
        .size = sizeof(struct Object),
        .dataGet = NULL,
        .dataOffsets = NULL,
        .dataSizes = NULL,
        .abstract = false,

        ._ctor = _ctor,
        .caller_ctor = caller_Object_ctor,
        .this_ctor = Object_ctor,
        ._dtor = _dtor,
        .caller_dtor = caller_Object_dtor,
        .this_dtor = Object_dtor,
        ._equals = _equals,
        .caller_equals = caller_Object_equals,
        .this_equals = Object_equals,
        ._deepcopy = _deepcopy,
        .caller_deepcopy = caller_Object_deepcopy,
        .this_deepcopy = Object_deepcopy,
};

const void* const Object(){
    return &object;
}
/* END Object Description */





