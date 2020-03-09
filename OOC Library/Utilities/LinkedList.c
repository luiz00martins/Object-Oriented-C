
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"
#include "LinkedList.r"
#include "../Wrappers/PrimWrapper.h"



/** START Getters and Setters **/
object_build_getset(head)
build_decl_get(len);
build_decl_get(type);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(LinkedList,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (get, (int, i)),
            (add, (int, i, void*, obj)),
            (remove, (int, i)),
            (pop, (int, i)),
            (clear, ()),
            (contains, (void*, obj)),
            (ofType, (void*, class)),
            (print, (int, bound)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedList,
                 ((LinkedNode*, head), (int, len), (struct Class*, type)),
                 ((print, (int, bound))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedList_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_ctor(LinkedList(), self, args);

    // Gathering arguments
    linkedList->type = va_arg(*args, void*);

    linkedList->len = 0;
    linkedList->head = NULL;

    return self;
}
void* LinkedList_dtor(void* self){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_dtor(LinkedList(), self);

    if(linkedList->len > 0){

    LinkedNode* aux;
        for(int i = 0; i < (linkedList->len); i++){
            aux = linkedList->head;
            linkedList->head = aux->next;
            free(aux);
        }
      linkedList->len = 0;
    }

    return self;
}
void* LinkedList_get(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_get(LinkedList(), self, i);

    if(linkedList->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }
    if(i < 0 || i >= linkedList->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    int cont = 0;
    LinkedNode* aux = linkedList->head;
    if(i == 0){
        return aux->obj;
    }
    for(cont = 1; cont < i; cont++){
        aux = aux->next->obj;
    }

    return aux;
}
void* LinkedList_add(void* self, int i, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_add(LinkedList(), self, i, obj);

    if(i < 0){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    if (i > linkedList->len)
        i = linkedList->len;

    LinkedNode* novoNo = malloc(sizeof(struct LinkedNode));
    novoNo->obj = obj;
    novoNo->next = NULL;

    if(linkedList->len == 0){
        linkedList->head = novoNo;
    }
    else if(i == 0){
        novoNo->next = linkedList->head;
        linkedList->head = novoNo;
    }
    else{
        int cont;
        LinkedNode* aux = linkedList->head;
        for(cont = 1; cont < i; cont++){
            aux = aux->next;
        }
        novoNo->next = aux->next;
        aux->next = novoNo;
    }
    linkedList->len++;

    return NULL;
}
void* LinkedList_remove(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_remove(LinkedList(), self, i);

    if(i < 0 || i >= linkedList->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    LinkedNode* aux = linkedList->head;
    LinkedNode* p;
    if(i == 0){
        linkedList->head = aux->next;
        free(aux);
    }
    else{
        for(cont = 1; cont < i; cont++){
            aux = aux->next;
        }
        p = aux->next;
        aux->next = aux->next->next;
        free(p);
    }
    linkedList->len--;

    return NULL;
}
void* LinkedList_push(void* self, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);

    add(linkedList, linkedList->len, obj);

    return NULL;
}
void* LinkedList_pop(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_pop(LinkedList(), self, i);

    if(i < 0 || i >= linkedList->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    if(linkedList->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    LinkedNode* aux = linkedList->head;
    LinkedNode* p;
    void* obj = aux->obj;
    if(i == 0){
        linkedList->head = aux->next;
        free(aux);
    }
    else{
        for(cont = 1; cont < i; cont++){
            aux = aux->next;
        }
        p = aux->next;
        aux->next = aux->next->next;
        obj = p->obj;
        free(p);
    }
    linkedList->len--;

    return obj;
}
void* LinkedList_clear(void* self){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_clear(LinkedList(), self);

    LinkedNode* aux;
    for(int i = 0; i < linkedList->len; i++){
        aux = linkedList->head;
        linkedList->head = aux->next;
        free(aux);
    }
    linkedList->len = 0;

    return NULL;
}
void* LinkedList_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_contains(LinkedList(), self, obj);

    bool returned = true;

    LinkedNode* aux = linkedList->head;
    for(int i = 0; i < linkedList->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(returned);
        aux = aux->next;
    }

    returned = false;
    return returning(returned);
}
void* LinkedList_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_indexOf(LinkedList(), self, obj);

    LinkedNode* aux = linkedList->head;
    for(int i = 0; i < linkedList->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            return returning(i);
        aux = aux->next;
    }

    int i = -1;
    return returning(i);
}
void* LinkedList_ofType(void* self, void* class){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_ofType(LinkedList(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(linkedList->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
void* LinkedList_print(void* self, int bound){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    LinkedNode* aux;
    int i;
    if(linkedList->len == 0){
        printf("|");
        for(i = 0; i < bound; i++)
            printf(" ");
        printf("|\n");
    }
    for(i = 0, aux = linkedList->head; i < linkedList->len; i++){
        printf("|");
        printBound(aux->obj, bound);
        printf("|\n");
        if(i < linkedList->len-1){
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
static const void* _LinkedListClass;

const void* const LinkedListClass(){
    return _LinkedListClass ? _LinkedListClass :
           (_LinkedListClass = new(ListClass(), "LinkedListClass", ListClass(), sizeof(struct LinkedListClass),
                                  _ctor, LinkedListClass_ctor,
                                  NULL));
}

static const void* _LinkedList;

const void* const LinkedList(){
    return _LinkedList ? _LinkedList :
           (_LinkedList = new(LinkedListClass(), "LinkedList", List(), sizeof(struct LinkedList),
                             _ctor, LinkedList_ctor,
                             _dtor, LinkedList_dtor,
                             _get, LinkedList_get,
                             _add, LinkedList_add,
                             _remove, LinkedList_remove,
                             _push, LinkedList_push,
                             _pop, LinkedList_pop,
                             _clear, LinkedList_clear,
                             _contains, LinkedList_contains,
                             _indexOf, LinkedList_indexOf,
                             _ofType, LinkedList_ofType,
                             _print, LinkedList_print,
                             NULL));
}
/* END Dynamic initializer */
