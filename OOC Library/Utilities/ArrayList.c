
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayList.h"
#include "ArrayList.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME ArrayList
newClass(List,
    (default, ctor),
    (default, dtor),
    (default, get),
    (default, add),
    (default, remove),
    (default, push),
    (default, pop),
    (default, clear),
    (default, resize),
    (default, contains),
    (default, indexOf),
    (default, ofType),
    (default, print)
)

/* Overloaded: */
define_method(ctor){
    param(class, type);
    callSuperMethod();

    // Gathering arguments
    self->type = type;

    self->size = 1;
    self->len = 0;
    self->objs = malloc(sizeof(void*));

    returning(ArrayList, self);
}
define_method(dtor){
    callSuperMethod();

    free(self->objs);

    returning(ArrayList, self);
}
define_method(get){
    param(int, i);
    callSuperMethod(i);


    if(i < 0 || i >= self->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    return self->objs[i];
}
define_method(add){
    param(int, i);
    param(Object, obj);
    cast(self->type, obj);
    callSuperMethod(i, obj);

    if(i < 0){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    if(i > self->len){
        i = self->len;
    }

    if(self->len == self->size){
        resize(self, self->size * 2);
    }

    /*if(self->objs[i] == NULL){
        self->objs[i] = obj;
    }*/
    int cont;
    for(cont = self->len; cont > i; cont--){
        self->objs[cont] = self->objs[cont-1];
    }

    self->objs[i] = obj;
    (self->len)++;

    returning();
}
define_method(remove){
    param(int, i);

    if(i < 0 || i > self->len) returning();

    int cont;
    for(cont = i; cont < self->len; cont++){
        self->objs[cont] = self->objs[cont+1];
    }
    self->len--;

    returning();
}
define_method(push){
    param(Object, obj);
    cast(self->type, obj);

    add(self, self->len, obj);

    returning();
}
define_method(pop){
    param(int, i);
    callSuperMethod(i);

    if(i < 0 || i >= self->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    pointer aux = self->objs[i];

    for(cont = i; cont < self->len; cont++){
        self->objs[cont] = self->objs[cont+1];
    }
    (self->len)--;

    returning(pointer, aux);
}
define_method(clear){
    callSuperMethod();

    self->len=0;

    returning();
}
define_method(resize){
    param(int, size);

    if(size < 0){
        printf("\nERROR: Cannot resize to %i\n", size);
        fflush(stdout);
        assert(0);
    }
    if(size == 0){
        if(self->len)
            size = self->len;
        else
            size = 1;
    }

    void** newObjs = malloc(sizeof(void*) * size);

    int smallestLen = size < self->len ? size : self->len;

    memcpy(newObjs, self->objs, sizeof(void*) * smallestLen);

    free(self->objs);

    self->objs = (struct Object**)newObjs;
    self->len = smallestLen;
    self->size = size;

    returning();
}
define_method(contains){
    param(Object, obj);
    cast(self->type, obj);
    callSuperMethod(obj);

    bool returned = true;

    for(int i = 0; i < self->len; i++){
        if(as(bool, equals(self->objs[i], obj)))
            returning(bool, returned);
    }

    returned = false;
    returning(bool, returned);
}
define_method(indexOf){
    param(Object, obj);
    cast(self->type, obj);
    callSuperMethod(obj);

    for(int i = 0; i < self->len; i++){
        if(as(bool, equals(self->objs[i], obj)))
            returning(int, i);
    }

    int returned = -1;
    returning(int, returned);
}
// TODO: Push this to List, maybe to the not yet build "Collection"
define_method(ofType){
    param(class, testClass);
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

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    // Printing valid values
    for (int i = 0; i < self->len; i++){
        printf("|");
        printBound(self->objs[i], bound);
        printf("|\n");
        if(i < self->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    // Printing empty values
    for (int i = self->len; i < self->size; i++){
        printf("|%*s|\n", bound, "");
        if(i < self->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");

    returning();
}

