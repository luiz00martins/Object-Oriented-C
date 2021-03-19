
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"
#include "LinkedList.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME LinkedList
newClass(List,
    (default, ctor),
    (default, dtor),
    (default, get),
    (default, add),
    (default, remove),
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

    returning(LinkedList, self);
}
define_method(dtor){
    // Calling super constructor
    callSuperMethod();

    if(self->len > 0){

    LinkedNode* aux;
        for(int i = 0; i < (self->len); i++){
            aux = self->head;
            self->head = aux->next;
            free(aux);
        }
      self->len = 0;
    }

    returning(LinkedList, self);
}
define_method(get){
    param(int, i);
    // Calling super constructor
    callSuperMethod(i);

    if(self->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }
    if(i < 0 || i >= self->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    int cont = 0;
    LinkedNode* aux = self->head;
    if(i == 0){
        return aux->obj;
    }
    for(cont = 1; cont < i; cont++){
        aux = aux->next;
    }

    return aux;
}
define_method(add){
    param(int, i);
    param(Object, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(i, obj);

    if(i < 0){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    if (i > self->len)
        i = self->len;

    LinkedNode* novoNo = malloc(sizeof(struct LinkedNode));
    novoNo->obj = obj;
    novoNo->next = NULL;

    if(self->len == 0){
        self->head = novoNo;
    }
    else if(i == 0){
        novoNo->next = self->head;
        self->head = novoNo;
    }
    else{
        int cont;
        LinkedNode* aux = self->head;
        for(cont = 1; cont < i; cont++){
            aux = aux->next;
        }
        novoNo->next = aux->next;
        aux->next = novoNo;
    }
    self->len++;

    returning();
}
define_method(remove){
    param(int, i);
    // Calling super constructor
    callSuperMethod(i);

    if(i < 0 || i >= self->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    LinkedNode* aux = self->head;
    LinkedNode* p;
    if(i == 0){
        self->head = aux->next;
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
    self->len--;

    returning();
}
define_method(push){
    param(class, obj);
    cast(self->type, obj);
    // Calling super constructor

    add(self, self->len, obj);

    returning();
}
define_method(pop){
    param(int, i);
    // Calling super constructor
    callSuperMethod(i);

    if(i < 0 || i >= self->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }
    if(self->len == 0){
        printf("\nERROR: Cannot pop item from empty list\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    LinkedNode* aux = self->head;
    LinkedNode* p;
    void* obj = aux->obj;
    if(i == 0){
        self->head = aux->next;
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
    self->len--;

    return obj;
}
define_method(clear){
    // Calling super constructor
    callSuperMethod();

    LinkedNode* aux;
    for(int i = 0; i < self->len; i++){
        aux = self->head;
        self->head = aux->next;
        free(aux);
    }
    self->len = 0;

    returning();
}
define_method(contains){
    param(class, obj);
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
    param(class, obj);
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

