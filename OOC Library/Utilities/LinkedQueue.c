
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedQueue.h"
#include "LinkedQueue.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME LinkedQueue
newClass(Queue,
    (default, ctor),
    (default, dtor),
    (default, peek),
    (default, push),
    (default, pop),
    (default, clear),
    (default, contains),
    (default, indexOf),
    (default, ofType),
    (default, print)
)

/* Overloaded: */
define_method(ctor){
    param(class, type);
    // Calling super constructor
    callSuperMethod(args);

    // Gathering arguments
    self->type = type;
    self->len = 0;
    self->head = NULL;

    returning(LinkedQueue, self);
}
define_method(dtor){    // Calling super constructor
    callSuperMethod();

    if(self->len > 0){

    LinkedNode* aux;
        for(int i = 1; i <= (self->len); i++){
            aux = self->head;
            self->head = aux->next;
            free(aux);
        }
     self->len = 0;
    }
    else printf("Fila vazia\n");

    returning(LinkedQueue, self);
}
define_method(peek){
    // Calling super constructor
    callSuperMethod();

    if(self->len == 0)returning();

    returning(self->type, self->head->obj);
}
define_method(push){
    param(Object, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    LinkedNode* novoNo = malloc(sizeof(struct LinkedNode));
    novoNo->obj = obj;
    novoNo->next = NULL;

    LinkedNode* aux = self->head;
    if(aux == NULL){
        self->head = novoNo;
    }
    else{
        for(int i = 1; i < self->len; i++){
            aux = aux->next;
        }
        aux->next = novoNo;
    }

    (self->len)++;

    returning();
}
define_method(pop){
    // Calling super constructor
    callSuperMethod();

    if(self->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }

    LinkedNode* aux = self->head;
    self->head = self->head->next;

    void* obj = aux->obj;
    free(aux);
    self->len--;

    return obj;
}
define_method(clear){
    // Calling super constructor
    callSuperMethod();

    LinkedNode* aux;
    for(int i = 1; i <= (self->len); i++){
        aux = self->head;
        self->head = aux->next;
        free(aux);
    }
    self->len = 0;

    returning();
}
define_method(contains){
    param(Object, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    bool returned = true;

    LinkedNode* aux = self->head;
    for(int i = 0; i < self->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            returning(bool, returned);
        aux = aux->next;
    }

    returned = false;
    returning(bool, returned);
}
define_method(indexOf){
    param(Object, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    LinkedNode* aux = self->head;
    for(int i = 0; i < self->len; i++){
        if(as(bool, equals(aux->obj, obj)))
            returning(int, i);
        aux = aux->next;
    }

    int i = -1;
    returning(int, i);
}
define_method(ofType){
    param(class, testClass);
    // Calling super constructor
    callSuperMethod(testClass);

    // Verifyting if it's really a class
    if(!isClass(testClass)){
        error("pointer is not a Class");
    }

    bool returned;
    if(self->type == testClass){
        returned = true;
        returning(bool, returned);
    }
    else {
        returned = false;
        returning(bool, returned);
    }
}
define_method(print){
    param(int, bound);
    // Calling super constructor

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    LinkedNode* aux;
    int i;
    if(self->len == 0){
        printf("|");
        for(i = 0; i < bound; i++)
            printf(" ");
        printf("|\n");
    }
    for(i = 0, aux = self->head; i < self->len; i++){
        printf("|");
        printBound(aux->obj, bound);
        printf("|\n");
        if(i < self->len-1){
            for(int j = 0; j < bound+2; j++)
                printf("=");
            printf("\n");
        }
        aux = aux->next;
    }
    for(i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");

    returning();
}