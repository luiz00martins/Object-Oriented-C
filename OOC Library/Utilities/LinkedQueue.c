
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedQueue.h"
#include "LinkedQueue.r"
#include "../Wrappers/PrimWrapper.h"


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
                 ((print, (int, bound))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedQueue_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_ctor(LinkedQueue(), self, args);

    // Gathering arguments
    linkedQueue->type = va_arg(*args, void*);
    linkedQueue->len = 0;
    linkedQueue->head = NULL;

    return self;
}
void* LinkedQueue_dtor(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_dtor(LinkedQueue(), self);

    if(linkedQueue->len > 0){

    LinkedNode* aux;
        for(int i = 1; i <= (linkedQueue->len); i++){
            aux = linkedQueue->head;
            linkedQueue->head = aux->next;
            free(aux);
        }
     linkedQueue->len = 0;
    }
    else printf("Fila vazia\n");

    return self;
}
void* LinkedQueue_peek(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_peek(LinkedQueue(), self);

    if(linkedQueue->len == 0)return NULL;

    return (linkedQueue->head->obj);
}
void* LinkedQueue_push(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_push(LinkedQueue(), self, obj);

    LinkedNode* novoNo = malloc(sizeof(struct LinkedNode));
    novoNo->obj = obj;
    novoNo->next = NULL;

    LinkedNode* aux = linkedQueue->head;
    if(aux == NULL){
        linkedQueue->head = novoNo;
    }
    else{
        for(int i = 1; i < linkedQueue->len; i++){
            aux = aux->next;
        }
        aux->next = novoNo;
    }

    (linkedQueue->len)++;

    return NULL;
}
void* LinkedQueue_pop(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_pop(LinkedQueue(), self);

    if(linkedQueue->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }

    LinkedNode* aux = linkedQueue->head;
    linkedQueue->head = linkedQueue->head->next;

    void* obj = aux->obj;
    free(aux);
    linkedQueue->len--;

    return obj;
}
void* LinkedQueue_clear(void* self){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_clear(LinkedQueue(), self);

    LinkedNode* aux;
    for(int i = 1; i <= (linkedQueue->len); i++){
        aux = linkedQueue->head;
        linkedQueue->head = aux->next;
        free(aux);
    }
    linkedQueue->len = 0;

    return NULL;
}
void* LinkedQueue_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_contains(LinkedQueue(), self, obj);

    bool returned = true;

    LinkedNode* aux = linkedQueue->head;
    for(int i = 0; i < linkedQueue->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(returned);
        aux = aux->next;
    }

    returned = false;
    return returning(returned);
}
void* LinkedQueue_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedQueue* linkedQueue = cast(LinkedQueue(), self);
    super_indexOf(LinkedQueue(), self, obj);

    LinkedNode* aux = linkedQueue->head;
    for(int i = 0; i < linkedQueue->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(i);
        aux = aux->next;
    }

    int i = -1;
    return returning(i);
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

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    LinkedNode* aux;
    int i;
    if(linkedQueue->len == 0){
        printf("|");
        for(i = 0; i < bound; i++)
            printf(" ");
        printf("|\n");
    }
    for(i = 0, aux = linkedQueue->head; i < linkedQueue->len; i++){
        printf("|");
        printBound(aux->obj, bound);
        printf("|\n");
        if(i < linkedQueue->len-1){
            for(int j = 0; j < bound+2; j++)
                printf("=");
            printf("\n");
        }
        aux = aux->next;
    }
    for(i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");

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
