#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Char.h"
#include "Char.r"

#define CLASS_NAME Char
newClass(PrimWrapper,
    (default, ctor),
    (default, dataSize),
    (default, print),
    (default, printBound),
    (default, scan),
    (default, equals),
    (default, lessThan),
    (default, greaterThan),
    (default, get)
)


define_method(ctor){
    paramOptional(char, val, '\0');

    self->data = val;
    returning(Char, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(char);
    returning(int, returned);
}

define_method(print){

    printf("%c", self->data);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than 5\n");
    }

    if(bound) {
        printf("%c", self->data);
        for (int i = 0; i < bound-1; i++){
            printf(" ");
        }
    }

    returning();
}

define_method(scan){

    scanf("%c", &self->data);

    returning();
}

define_method(equals){
    param(Char, obj);

    bool returned = true;

    if(as(bool, callSuperMethod(obj)))
        returning(bool, returned);

    if(self->data == obj->data){
        returning(bool, returned);
    }
    else{
        returned = false;
        returning(bool, returned);
    }
}

define_method(lessThan){
    param(Char, comp);

    if(self->data < comp->data) {
        bool returned = true;
        returning(bool, returned);
    }
    else {
        bool returned = false;
        returning(bool, returned);
    }
}

define_method(greaterThan){
    param(Char, comp);

    if(self->data > comp->data) {
        bool returned = true;
        returning(bool, returned);
    }
    else {
        bool returned = false;
        returning(bool, returned);
    }
}

define_method(get){
    returning(char, self->data);
}


/* END Dynamic initializer */
