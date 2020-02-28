
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>
#include "Object.h"
#include "Object.r"

// TODO: Implement get and set as a keyword, to get super variables
// TODO: Add copy function (and perhaps a deepcopy function) with error message "function not defined"

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
        assert(0 /* Cannot instantiate abstract object */);
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
    assert(self);
    return *((const struct Class**)self);
}
int sizeOf(const void* self){
    const struct Class* selfClass = getClass(self);
    assert(self);

    return selfClass->size;
}
/**
 * Returns a boolean for if the object {@code self} is of the class {@code class}
 *
 * @param self Object
 * @param class Class
 * @return {@code true} if the object {@code self} is of the class {@code class}, {@code false}
 */
bool isClass(const void* self, const struct Class* class){
    const struct Class* selfClass = getClass(self);
    assert(selfClass && class);

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
    if (class == Class() || isClass(self, class)){
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

    printf("\nERROR: Abstract method called");
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

single_build_caller_funcs(ctor)
single_build_caller_funcs(dtor)
single_build_caller_funcs(deepcopy)

/** START Caller functions **/
// TODO [IMPORTANT]: THE ERROR IS HAPPENING HERE
single_build_func(Object, ctor, (va_list*, nargs))

single_build_func(Object, dtor, ())

single_build_func(Object, deepcopy, ())


/* START Caller functions */


/* END Caller functions */

/* START Class function definitions */
void* Class_ctor(void* self, va_list* args){
    struct Class* classPtr = cast(Class(), self);

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
            classPtr->this_deepcopy == abstract){

        classPtr->abstract = true;
    }

    return self;
}

void* Class_dtor(void* self){
    assert(0 /* Classes are permanent, they should never call a destructor */);
    abstract(self, NULL);
}
/* END Class function definitions */

/* START Object function definitions */
void* Object_ctor(void* self, va_list* args){
    return cast(Object(), self);
}

void* Object_dtor(void* self){
    return cast(Object(), self);
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

        ._ctor = _ctor,
        .caller_ctor = caller_Object_ctor,
        .this_ctor = Class_ctor,
        ._dtor = _dtor,
        .caller_dtor = caller_Object_dtor,
        .this_dtor = Class_dtor,
        ._deepcopy = _deepcopy,
        .caller_deepcopy = caller_Object_dtor,
        .this_deepcopy = abstract,
};

const void* const Class(){
    return &class;
}
/* END Class Description */

/* START Object Description */
const struct Class object = {
        .object = &class,
        .name = "Object",
        .super = &class,
        .size = sizeof(struct Object),

        ._ctor = _ctor,
        .caller_ctor = caller_Object_ctor,
        .this_ctor = Object_ctor,
        ._dtor = _dtor,
        .caller_dtor = caller_Object_dtor,
        .this_dtor = Object_dtor,
        ._deepcopy = _deepcopy,
        .caller_deepcopy = caller_Object_deepcopy,
        .this_deepcopy = Object_deepcopy,
};

const void* const Object(){
    return &object;
}
/* END Object Description */





