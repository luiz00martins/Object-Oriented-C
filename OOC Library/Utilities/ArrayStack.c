
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayStack.h"
#include "ArrayStack.r"


/** START Getters and Setters **/
build_decl_get(objs);
build_decl_get(type);
build_decl_get(len);
build_decl_get(size);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(ArrayStack,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (resize, (int, size)),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))
/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(ArrayStack,
        ((void**, objs), (int, len), (int, size), (struct Class*, type)),
        ((resize, (int, size))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* ArrayStack_ctor(void* self, va_list* args){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_ctor(ArrayStack(), self, args);

    // Gathering arguments
    arrayStack->type = va_arg(*args, void*);

    return self;
}
void* ArrayStack_dtor(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_dtor(ArrayStack(), self);



    return self;
}
void* ArrayStack_peek(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_peek(ArrayStack(), self);



    return NULL;
}
void* ArrayStack_push(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_push(ArrayStack(), self, obj);



    return NULL;
}
void* ArrayStack_pop(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_pop(ArrayStack(), self);



    return NULL;
}
void* ArrayStack_clear(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_clear(ArrayStack(), self);



    return NULL;
}
void* ArrayStack_resize(void* self, int size){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);



    return NULL;
}
void* ArrayStack_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_contains(ArrayStack(), self, obj);



    return NULL;
}
void* ArrayStack_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_indexOf(ArrayStack(), self, obj);



    return NULL;
}
void* ArrayStack_ofType(void* self, void* class){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_ofType(ArrayStack(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(arrayStack->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ArrayStackClass;

const void* const ArrayStackClass(){
    return _ArrayStackClass ? _ArrayStackClass :
           (_ArrayStackClass = new(StackClass(), "ArrayStackClass", StackClass(), sizeof(struct ArrayStackClass),
                               _ctor, ArrayStackClass_ctor,
                               NULL));
}

static const void* _ArrayStack;

const void* const ArrayStack(){
    return _ArrayStack ? _ArrayStack :
           (_ArrayStack = new(ArrayStackClass(), "ArrayStack", Stack(), sizeof(struct ArrayStack),
                          _ctor, ArrayStack_ctor,
                          _dtor, ArrayStack_dtor,
                          _peek, ArrayStack_peek,
                          _push, ArrayStack_push,
                          _pop, ArrayStack_pop,
                          _clear, ArrayStack_clear,
                          _resize, ArrayStack_resize,
                          _contains, ArrayStack_contains,
                          _indexOf, ArrayStack_indexOf,
                          _ofType, ArrayStack_ofType,
                          NULL));
}
/* END Dynamic initializer */
