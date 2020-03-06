
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedStack.h"
#include "LinkedStack.r"


/** START Getters and Setters **/
build_decl_get(len);
build_decl_get(head);
build_decl_get(type);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(LinkedStack,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedStack,
                 ((LinkedNode*, head), (int, len), (struct Class*, type)),
                 ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedStack_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_ctor(LinkedStack(), self, args);

    // Gathering arguments
    linkedStack->type = va_arg(*args, void*);

    return self;
}
void* LinkedStack_dtor(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_dtor(LinkedStack(), self);



    return self;
}
void* LinkedStack_peek(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_peek(LinkedStack(), self);



    return NULL;
}
void* LinkedStack_push(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_push(LinkedStack(), self, obj);



    return NULL;
}
void* LinkedStack_pop(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_pop(LinkedStack(), self);



    return NULL;
}
void* LinkedStack_clear(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_clear(LinkedStack(), self);



    return NULL;
}
void* LinkedStack_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_contains(LinkedStack(), self, obj);



    return NULL;
}
void* LinkedStack_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_indexOf(LinkedStack(), self, obj);



    return NULL;
}
void* LinkedStack_ofType(void* self, void* class){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_ofType(LinkedStack(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(linkedStack->type == class){
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
static const void* _LinkedStackClass;

const void* const LinkedStackClass(){
    return _LinkedStackClass ? _LinkedStackClass :
           (_LinkedStackClass = new(StackClass(), "LinkedStackClass", StackClass(), sizeof(struct LinkedStackClass),
                                  _ctor, LinkedStackClass_ctor,
                                  NULL));
}

static const void* _LinkedStack;

const void* const LinkedStack(){
    return _LinkedStack ? _LinkedStack :
           (_LinkedStack = new(LinkedStackClass(), "LinkedStack", Stack(), sizeof(struct LinkedStack),
                             _ctor, LinkedStack_ctor,
                             _dtor, LinkedStack_dtor,
                             _peek, LinkedStack_peek,
                             _push, LinkedStack_push,
                             _pop, LinkedStack_pop,
                             _clear, LinkedStack_clear,
                             _contains, LinkedStack_contains,
                             _indexOf, LinkedStack_indexOf,
                             _ofType, LinkedStack_ofType,
                             NULL));
}
/* END Dynamic initializer */