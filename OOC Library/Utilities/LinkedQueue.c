
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedQueue.h"
#include "LinkedQueue.r"


/** START Getters and Setters **/
build_decl_get(len);
build_decl_get(head);
build_decl_get(type);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(LinkedQueue,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)),
            (print, (int, bound)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedQueue,
                 ((LinkedNode*, head), (int, len), (struct Class*, type)),
                 ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedQueue_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_ctor(LinkedQueue(), self, args);

    // Gathering arguments
    linkedQueue->type = va_arg(*args, void*);

    return self;
}
void* LinkedQueue_dtor(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_dtor(LinkedQueue(), self);



    return self;
}
void* LinkedQueue_peek(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_peek(LinkedQueue(), self);



    return NULL;
}
void* LinkedQueue_push(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_push(LinkedQueue(), self, obj);



    return NULL;
}
void* LinkedQueue_pop(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_pop(LinkedQueue(), self);



    return NULL;
}
void* LinkedQueue_clear(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_clear(LinkedQueue(), self);



    return NULL;
}
void* LinkedQueue_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_contains(LinkedQueue(), self, obj);



    return NULL;
}
void* LinkedQueue_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_indexOf(LinkedQueue(), self, obj);



    return NULL;
}
void* LinkedQueue_ofType(void* self, void* class){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_ofType(LinkedQueue(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(linkedQueue->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
void* LinkedQueue_print(void* self, int bound){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);

    /*
    // Figuring out which one should be printed
    bool* printed = malloc(sizeof(bool) * arrayQueue->size);
    for (int i = 0; i < arrayQueue->size; i++)
        printed[i] = false;

    if (arrayQueue->start < arrayQueue->end){
        for(int i = 0; i < arrayQueue->size; i++){
            if(i >= arrayQueue->start && i <= arrayQueue->end)
                printed[i] = true;
        }
    }
    else if (arrayQueue->end < arrayQueue->start){
        for(int i = 0; i < arrayQueue->size; i++){
            if(i >= arrayQueue->start || i <= arrayQueue->end)
                printed[i] = true;
        }
    }
    else if (arrayQueue->len == 1){
        printed[arrayQueue->start] = true;
    }


    //Printing
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    for (int i = 0; i < arrayQueue->size; i++){
        if(printed[i])
            print(arrayQueue->objs[i], bound);
        else {
            printf("|%*s|\n", bound, "");
        }
        if(i < arrayQueue->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");


    free(printed);
    */

    return NULL;
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _LinkedQueueClass;

const void* const LinkedQueueClass(){
    return _LinkedQueueClass ? _LinkedQueueClass :
           (_LinkedQueueClass = new(QueueClass(), "LinkedQueueClass", QueueClass(), sizeof(struct LinkedQueueClass),
                                  _ctor, LinkedQueueClass_ctor,
                                  NULL));
}

static const void* _LinkedQueue;

const void* const LinkedQueue(){
    return _LinkedQueue ? _LinkedQueue :
           (_LinkedQueue = new(LinkedQueueClass(), "LinkedQueue", Queue(), sizeof(struct LinkedQueue),
                             _ctor, LinkedQueue_ctor,
                             _dtor, LinkedQueue_dtor,
                             _peek, LinkedQueue_peek,
                             _push, LinkedQueue_push,
                             _pop, LinkedQueue_pop,
                             _clear, LinkedQueue_clear,
                             _contains, LinkedQueue_contains,
                             _indexOf, LinkedQueue_indexOf,
                             _ofType, LinkedQueue_ofType,
                             _print, LinkedQueue_print,
                             NULL));
}
/* END Dynamic initializer */
