
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayQueue.h"
#include "ArrayQueue.r"


/** START Getters and Setters **/
object_build_getset(start, end)
build_decl_get(objs);
build_decl_get(type);
build_decl_get(len);
build_decl_get(size);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(ArrayQueue,
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
build_class_ctor(ArrayQueue,
        ((void**, objs), (int, len), (int, size), (int, start), (int, end), (struct Class*, type)),
        ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
void internal_doubleSize(void* self){
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);

}

void internal_halveSize(void* self){
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);

}

/* Overloaded: */
void* ArrayQueue_ctor(void* self, va_list* args){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_ctor(ArrayQueue(), self, args);

    // Gathering arguments
    arrayQueue->type = va_arg(*args, void*);


    arrayQueue->objs = malloc(sizeof(void*));
    arrayQueue->size = 1;
    arrayQueue->len = 0;
    arrayQueue->start = 0;
    arrayQueue->end = 0;

    return self;
}
void* ArrayQueue_dtor(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_dtor(ArrayQueue(), self);

    free(arrayQueue->objs);

    return self;
}
void* ArrayQueue_peek(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_peek(ArrayQueue(), self);



    return arrayQueue->objs[arrayQueue->start];
}
void* ArrayQueue_push(void* self, void* obj){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_push(ArrayQueue(), self, obj);



    return NULL;
}
void* ArrayQueue_pop(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_pop(ArrayQueue(), self);



    return NULL;
}
void* ArrayQueue_clear(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_clear(ArrayQueue(), self);



    return NULL;
}
void* ArrayQueue_resize(void* self, int size){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_resize(ArrayQueue(), self, size);



    return NULL;
}
void* ArrayQueue_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_contains(ArrayQueue(), self, obj);



    return NULL;
}
void* ArrayQueue_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_indexOf(ArrayQueue(), self, obj);



    return NULL;
}
void* ArrayQueue_ofType(void* self, void* class){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_ofType(ArrayQueue(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(arrayQueue->type == class){
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
static const void* _ArrayQueueClass;

const void* const ArrayQueueClass(){
    return _ArrayQueueClass ? _ArrayQueueClass :
           (_ArrayQueueClass = new(QueueClass(), "ArrayQueueClass", QueueClass(), sizeof(struct ArrayQueueClass),
                               _ctor, ArrayQueueClass_ctor,
                               NULL));
}

static const void* _ArrayQueue;

const void* const ArrayQueue(){
    return _ArrayQueue ? _ArrayQueue :
           (_ArrayQueue = new(ArrayQueueClass(), "ArrayQueue", Queue(), sizeof(struct ArrayQueue),
                          _peek, ArrayQueue_peek,
                          _push, ArrayQueue_push,
                          _pop, ArrayQueue_pop,
                          _clear, ArrayQueue_clear,
                          _resize, ArrayQueue_resize,
                          _contains, ArrayQueue_contains,
                          _indexOf, ArrayQueue_indexOf,
                          _ofType, ArrayQueue_ofType,
                          NULL));
}
/* END Dynamic initializer */
