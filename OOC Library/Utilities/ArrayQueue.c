
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
        ((resize, (int, size))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
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

    if(arrayQueue->size == arrayQueue->len){
        ArrayQueue_resize(arrayQueue, arrayQueue->size * 2);
    }

    // Finding the end
    int index = arrayQueue->end + 1;
    if(index == arrayQueue->size)
        index = 0;

    // Adding object, adjusting end and len
    arrayQueue->objs[index] = obj;
    arrayQueue->end = index;
    arrayQueue->len++;

    return NULL;
}
void* ArrayQueue_pop(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_pop(ArrayQueue(), self);

    if(arrayQueue->len == 0){
        printf("\nERROR: Cannot pop item from empty queue\n");
        fflush(stdout);
        assert(0);
    }

    // Storing item to be returned
    void* returned = arrayQueue->objs[arrayQueue->start];

    // Adjusting start and len
    arrayQueue->len--;
    // Start should only increase of it's not the last removal
    if(arrayQueue->len > 0)
        arrayQueue->start++;
    if(arrayQueue->start == arrayQueue->size)
        arrayQueue->start = 0;


    return returned;
}
void* ArrayQueue_clear(void* self){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_clear(ArrayQueue(), self);

    arrayQueue->len = 0;
    arrayQueue->start = 0;
    arrayQueue->end = 0;

    return NULL;
}
void* ArrayQueue_resize(void* self, int size){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);

    if(size < -1){
        printf("\nERROR: Cannot resize to %i\n", size);
        fflush(stdout);
        assert(0);
    }

    if(size == -1){
        size = arrayQueue->len;
    }

    void** newObjs = malloc(sizeof(void*) * size);

    int smallestLen = size < arrayQueue->len ? size : arrayQueue->len;

    // Note: If they are equal, you have nothing to copy
    if(arrayQueue->start < arrayQueue->end){
        // In case start is before end, just copy from start to end
        memcpy(newObjs, arrayQueue->objs+arrayQueue->start, sizeof(void*) * smallestLen);
    }
    else{
        // In case end is before start
        int toBeCopied = smallestLen;

        // Copy the least you need
        int copiedStart = size < (arrayQueue->size-arrayQueue->start) ? size : (arrayQueue->size-arrayQueue->start);
        // Copy from start to the last object (or until you've copied everything)
        memcpy(newObjs, arrayQueue->objs+arrayQueue->start, sizeof(void*) * copiedStart);

        toBeCopied -= copiedStart;

        if(toBeCopied > 0){
            // Then from the first object to the end to the now tail
            memcpy(newObjs + copiedStart, arrayQueue->objs, sizeof(void*) *toBeCopied);
        }
    }
    free(arrayQueue->objs);

    arrayQueue->objs = newObjs;
    arrayQueue->size = size;
    arrayQueue->len = smallestLen;
    arrayQueue->start = 0;
    arrayQueue->end = smallestLen - 1;

    return NULL;
}
void* ArrayQueue_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_contains(ArrayQueue(), self, obj);

    bool returned = false;


    if(arrayQueue->start < arrayQueue->end){
        int i;
        for (i = arrayQueue->start; i < arrayQueue->end+1; i++){
            if (arrayQueue->objs[i] == obj){
                returned = true;
                return returning(returned);
            }
        }
    }
    else{
        int i;
        // Go from start to the last object
        for (i = arrayQueue->start; i < arrayQueue->size; i++){
            if (arrayQueue->objs[i] == obj){
                returned = true;
                return returning(returned);
            }
        }
        // From the first object to end
        for (i = 0; i < arrayQueue->end+1; i++){
            if (arrayQueue->objs[i] == obj){
                returned = true;
                return returning(returned);
            }
        }
    }


    return returning(returned);
}
void* ArrayQueue_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayQueue* arrayQueue = cast(ArrayQueue(), self);
    super_indexOf(ArrayQueue(), self, obj);

    int index = 0;


    if(arrayQueue->start < arrayQueue->end){
        int i;
        for (i = arrayQueue->start; i < arrayQueue->end+1; i++, index++){
            if (arrayQueue->objs[i] == obj){
                return returning(index);
            }
        }
    }
    else{
        int i;
        // Go from start to the last object
        for (i = arrayQueue->start; i < arrayQueue->size; i++, index++){
            if (arrayQueue->objs[i] == obj){
                return returning(index);
            }
        }
        // From the first object to end
        for (i = 0; i < arrayQueue->end+1; i++){
            if (arrayQueue->objs[i] == obj){
                return returning(index);
            }
        }
    }

    index = -1;
    return returning(index);
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
                          _ctor, ArrayQueue_ctor,
                          _dtor, ArrayQueue_dtor,
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
