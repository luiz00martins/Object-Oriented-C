
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayQueue.h"
#include "ArrayQueue.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME ArrayQueue
newClass(Queue,
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
    self->size = 1;
    self->len = 0;
    self->start = 0;
    self->end = 0;

    returning(ArrayQueue, self);
}
define_method(dtor){
    // Calling super constructor
    callSuperMethod();

    free(self->objs);

    returning(ArrayQueue, self);
}
define_method(peek){
    // Calling super constructor
    callSuperMethod();

    if(self->len > 0){
        returning(self->type, self->objs[self->start]);
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

    // Finding the end
    int index = self->end + 1;
    if(index == self->size)
        index = 0;

    // Adding object, adjusting end and len
    self->objs[index] = obj;
    self->end = index;
    self->len++;

    returning();
}
define_method(pop){
    // Calling super constructor
    callSuperMethod();

    if(self->len == 0){
        printf("\nERROR: Cannot pop item from empty queue\n");
        fflush(stdout);
        assert(0);
    }

    // Storing item to be returned
    struct Object* returned = self->objs[self->start];

    // Adjusting start and len
    self->len--;
    // Start should only increase of it's not the last removal
    if(self->len > 0)
        self->start++;
    if(self->start == self->size)
        self->start = 0;


    returning(Object, returned);
}
define_method(clear){
    // Calling super constructor
    callSuperMethod();

    self->len = 0;
    self->start = 0;
    self->end = 0;

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

    int smallestLen;

    if(size == 0){
        if(self->len)
            size = self->len;
        else
            size = 1;
    }

    void** newObjs = malloc(sizeof(void*) * size);

    smallestLen = size < self->len ? size : self->len;

    // Note: If they are equal, you have nothing to copy
    if(self->start < self->end){
        // In case start is before end, just copy from start to end
        memcpy(newObjs, self->objs+self->start, sizeof(void*) * smallestLen);
    }
    else{
        // In case end is before start
        int toBeCopied = smallestLen;

        // Copy the least you need
        int copiedStart = size < (self->size-self->start) ? size : (self->size-self->start);
        // Copy from start to the last object (or until you've copied everything)
        memcpy(newObjs, self->objs+self->start, sizeof(void*) * copiedStart);

        toBeCopied -= copiedStart;

        if(toBeCopied > 0){
            // Then from the first object to the end to the now tail
            memcpy(newObjs + copiedStart, self->objs, sizeof(void*) *toBeCopied);
        }
    }
    free(self->objs);

    self->objs = (struct Object**)newObjs;
    self->size = size;
    self->len = smallestLen;
    self->start = 0;
    self->end = smallestLen ? smallestLen - 1 : smallestLen;

    returning();
}
define_method(contains){
    param(class, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    bool returned = false;


    if(self->start < self->end){
        int i;
        for (i = self->start; i < self->end+1; i++){
            if (as(bool, equals(self->objs[i], obj))){
                returned = true;
                returning(bool, returned);
            }
        }
    }
    else{
        int i;
        // Go from start to the last object
        for (i = self->start; i < self->size; i++){
            if (as(bool, equals(self->objs[i], obj))){
                returned = true;
                returning(bool, returned);
            }
        }
        // From the first object to end
        for (i = 0; i < self->end+1; i++){
            if (equals(self->objs[i], obj)){
                returned = true;
                returning(bool, returned);
            }
        }
    }

    returning(bool, returned);
}
define_method(indexOf){
    param(class, obj);
    cast(self->type, obj);
    // Calling super constructor
    callSuperMethod(obj);

    int index = 0;


    if(self->start < self->end){
        int i;
        for (i = self->start; i < self->end+1; i++, index++){
            if (equals(self->objs[i], obj)){
                returning(int, index);
            }
        }
    }
    else{
        int i;
        // Go from start to the last object
        for (i = self->start; i < self->size; i++, index++){
            if (equals(self->objs[i], obj)){
                returning(int, index);
            }
        }
        // From the first object to end
        for (i = 0; i < self->end+1; i++){
            if (equals(self->objs[i], obj)){
                returning(int, index);
            }
        }
    }

    index = -1;
    returning(int, index);
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

    // Figuring out which one should be printed
    bool* printed = malloc(sizeof(bool) * self->size);
    for (int i = 0; i < self->size; i++)
        printed[i] = false;

    if (self->start < self->end){
        for(int i = 0; i < self->size; i++){
            if(i >= self->start && i <= self->end)
                printed[i] = true;
        }
    }
    else if (self->end < self->start){
        for(int i = 0; i < self->size; i++){
            if(i >= self->start || i <= self->end)
                printed[i] = true;
        }
    }
    else if (self->len == 1){
        printed[self->start] = true;
    }


    //Printing
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    for (int i = 0; i < self->size; i++){
        printf("|");
        if(printed[i])
            printBound(self->objs[i], bound);
        else {
            printf("%*s", bound, "");
        }
        printf("|\n");
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


    free(printed);

    returning();
}
