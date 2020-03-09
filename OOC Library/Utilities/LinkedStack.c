
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedStack.h"
#include "LinkedStack.r"
#include "../Wrappers/PrimWrapper.h"


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
            (ofType, (void*, class)),
            (print, (int, bound)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedStack,
                 ((LinkedNode*, head), (int, len), (struct Class*, type)),
                 ((print, (int, bound))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedStack_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_ctor(LinkedStack(), self, args);

    // Gathering arguments
    linkedStack->type = va_arg(*args, void*);
    linkedStack->len = 0;
    linkedStack->head = NULL;

    return self;
}
void* LinkedStack_dtor(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_dtor(LinkedStack(), self);

    if(linkedStack->len > 0){

    LinkedNode* aux;
        for(int i = 1; i <= (linkedStack->len); i++){
            aux = linkedStack->head;
            linkedStack->head = aux->next;
            free(aux);
        }
     linkedStack->len = 0;
    }
    else printf("Pilha vazia\n");

    return self;
}
void* LinkedStack_peek(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_peek(LinkedStack(), self);

    if(linkedStack->len == 0) return printf("Pilha vazia\n");
    else
    return (linkedStack->head)->obj;
}
void* LinkedStack_push(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_push(LinkedStack(), self, obj);

    LinkedNode* novoNo = malloc(sizeof(struct LinkedNode));
    novoNo->obj = obj;
    novoNo->next = NULL;
    LinkedNode* aux = linkedStack->head;

    novoNo->next = aux;
    linkedStack->head = novoNo;

    linkedStack->len++;

    return NULL;
}
void* LinkedStack_pop(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_pop(LinkedStack(), self);

    if(linkedStack->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }

    LinkedNode* aux = linkedStack->head;
    void* obj = aux->obj;
    linkedStack->head = linkedStack->head->next;
    free(aux);
    linkedStack->len--;
    return obj;
}
void* LinkedStack_clear(void* self){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_clear(LinkedStack(), self);

    LinkedNode* aux;
    for(int i = 1; i <= linkedStack->len; i++){
        aux = linkedStack->head;
        linkedStack->head = aux->next;
        free(aux);
    }
    linkedStack->len = 0;

    return NULL;
}
void* LinkedStack_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_contains(LinkedStack(), self, obj);

    bool returned = true;

    LinkedNode* aux = linkedStack->head;
    for(int i = 0; i < linkedStack->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(returned);
        aux = aux->next;
    }

    returned = false;
    return returning(returned);
}
void* LinkedStack_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);
    super_indexOf(LinkedStack(), self, obj);

    LinkedNode* aux = linkedStack->head;
    for(int i = 0; i < linkedStack->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(i);
        aux = aux->next;
    }

    int i = -1;
    return returning(i);
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
void* LinkedStack_print(void* self, int bound){
    // Calling super constructor
    struct LinkedStack* linkedStack = cast(LinkedStack(), self);

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    LinkedNode* aux;
    int i;
    if(linkedStack->len == 0){
        printf("|");
        for(i = 0; i < bound; i++)
            printf(" ");
        printf("|\n");
    }
    for(i = 0, aux = linkedStack->head; i < linkedStack->len; i++){
        printf("|");
        printBound(aux->obj, bound);
        printf("|\n");
        if(i < linkedStack->len-1){
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
                             _print, LinkedStack_print,
                             NULL));
}
/* END Dynamic initializer */
