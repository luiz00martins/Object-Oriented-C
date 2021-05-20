
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayStack.h"
#include "ArrayStack.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME ArrayStack
newClass(Stack,
    (default, ctor),
    (default, dtor),
    (default, peek),
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
    // Calling super constructor
    callSuperMethod();

    // Gathering arguments
    self->type = type;

    self->objs = malloc(sizeof(void*));
    self->len = 0;
    self->size = 1;

    returning(ArrayStack, self);
}
define_method(dtor){
    // Calling super constructor
    callSuperMethod();

    free(self->objs);

    returning(ArrayStack, self);
}
define_method(peek){
    // Calling super constructor
    callSuperMethod();

    if(self->len > 0) {
        returning(self->type, self->objs[self->len - 1]);
    }
    else {
        returning();
    }
}
define_method(push){
    param(Object, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    if(self->size == self->len){
        resize(self, self->size * 2);
    }

    self->objs[self->len] = obj;
    self->len++;

    returning();
}
define_method(pop){
    // Calling super constructor
    callSuperMethod();

    if(self->len == 0){
        printf("\nERROR: Cannot pop item from empty stack\n");
        fflush(stdout);
        assert(0);
    }

    self->len--;

    returning(self->type, self->objs[self->len]);
}
define_method(clear){
    // Calling super constructor
    callSuperMethod();

    self->len = 0;

    returning();
}
define_method(resize){
    param(int, size);
    // Calling super constructor

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
    param(class, obj);
    cast(self->type, obj);
    // Calling super constructor
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
    param(class, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    for(int i = 0; i < self->len; i++){
        if(as(bool, equals(self->objs[i], obj)))
            returning(int, i);
    }

    int returned = -1;
    returning(int, returned);
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


