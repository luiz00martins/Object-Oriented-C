
#include <stdlib.h>
#include <string.h>
#include <assert.h>
#include "Object.h"
#include "Object.r"

// Todo: Add default function with error message "function not defined"

void* new(const void* self, ...){
    assert(self);
    const struct Class* class = self;
    struct Object* object;
    va_list args;

    assert(class->size);
    object = malloc(class->size);
    assert(object);

    object->class = class;

    va_start(args, self);
    class->ctor(object, &args);
    va_end(args);

    return object;
}
void delete(void* self){
    assert(self);

    free(dtor(self));
}
const struct Class* getClass(const void* self){
    assert(self);
    return (const struct Class*)self;
}
int sizeOf(const void* self){
    const struct Class* selfClass = self;
    assert(self);

    return selfClass->size;
}

const void* super(const void* self){
    const struct Class* selfClass = self;
    assert(selfClass && selfClass->super);

    return selfClass->super;
}

/* START Caller functions */

/* HELPERS */
#define object_build_caller(FUNC, ARGS) \
    const struct Class* selfClass = ((const struct Object*)self)->class; \
    \
    assert(selfClass && selfClass->FUNC); \
    \
    return selfClass->FUNC ARGS

#define object_build_super_caller(FUNC, ARGS) \
    const struct Class* superclass = super(class); \
    \
    assert(self && superclass); \
    \
    return superclass->FUNC ARGS

void* ctor (void* self, va_list* args){
    object_build_caller(ctor, (self, args));
}
void* super_ctor(const struct Class* class, void* self, va_list* args){
    object_build_super_caller(ctor, (self, args));
}

void* dtor(void* self){
    object_build_caller(dtor, (self));
}
void* super_dtor(const struct Class* class, void* self){
    object_build_super_caller(dtor, (self));
}

bool is_class(const void* self, const struct Class* class){
    object_build_caller(is_class, (self, class));
}
bool super_is_class(const struct Class* class, void* self, struct Class* _class){
    object_build_super_caller(is_class, (self, _class));
}

bool of_class(const void* self, const struct Class* class){
    object_build_caller(of_class, (self, class));
}
bool super_of_class(const struct Class* class, void* self, struct Class* _class){
    object_build_super_caller(of_class, (self, _class));
}
/* END Caller functions */

/* START Class function definitions */
void* Class_ctor(void* self, va_list* args){
    struct Class* classPtr = self;

    classPtr->name = va_arg(*args, char*);
    classPtr->super = va_arg(*args, struct Class*);
    classPtr->size = va_arg(*args, size_t);

    assert(classPtr->super);

    /* Copying the function space */
    const size_t offset = offsetof(struct Class, ctor);
    /* Todo: Maybe this can be changed to a void* instead of char* */
    /* Todo [Important]: Change this to use classPtr->super, since it needs to inherit ctor and dtor from super, not object*/
    memcpy((char*) self + offset, (char*) classPtr->object + offset
            , sizeOf(classPtr->object) - offset);

    typedef void (* voidf) (); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    va_copy(funcArgs, *args);
    /* Function overload function */
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        if (selector == ctor){
            classPtr->ctor = function;
        }
        else if (selector == dtor) {
            classPtr->dtor = function;
        }
    }
    va_end(funcArgs);

    return self;
}

void* Class_dtor(void* self){
    assert(0 /* Can't destroy class type */);
}

bool Class_is_class(const void* self, const struct Class* class){
    const struct Class* selfClass = self;
    assert(selfClass && class);

    if (selfClass == class)
        return true;
    else
        return false;
}

bool Class_of_class(const void* self, const struct Class* class){
    if (Class_is_class(self, class)){
        return true;
    }
    else {
        if (class == Class){
            return false;
        }
        else {
            const struct Class* selfClass = self;
            return Class_of_class(selfClass->super, class);
        }
    }
}
/* END Class function definitions */

/* START Object function definitions */
void* Object_ctor(void* self, va_list* args){
    assert(self);

    return self;
}

void* Object_dtor(void* self){
    return self;
}
/* END Object function definitions */

/* START Class Description */
const struct Class class = {
        .object = &class,
        .name = "Class",
        .super = &class,
        .size = sizeof(struct Class),

        .ctor = Class_ctor,
        .dtor = Class_dtor,
        .is_class = Class_is_class,
        .of_class = Class_of_class
};

const struct Class* Class = &class;
/* END Class Description */

/* START Object Description */
const struct Class object = {
        .object = &class,
        .name = "Object",
        .super = &class,
        .size = sizeof(struct Object),

        .ctor = Object_ctor,
        .dtor = Object_dtor,
        .is_class = Class_is_class,
        .of_class = Class_of_class
};

const struct Object* Object = &object;
/* END Object Description */





