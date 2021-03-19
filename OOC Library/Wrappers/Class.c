#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Class.h"
#include "Class.r"

#define CLASS_NAME Class 
newClass(PrimWrapper,
    (default, ctor),
    (default, dataSize),
    (default, print),
    (default, printBound),
    (default, equals),
    (default, lessThan),
    (default, greaterThan),
    (default, get)
)


define_method(ctor){
    paramOptional(class, val, Object);

    self->data = val;
    returning(Class, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(class);
    returning(int, returned);
}

define_method(print){

    printf("%s", ((struct OOC_Class*)(self->data()))->name);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than 5\n");
    }

	char* str = ((struct OOC_Class*)(self->data()))->name;
	int len = strlen(str);

    if (bound < len) {
        for (int i = 0; i < bound - 3; i++)
            printf("%c", str[i]);
        printf("...");
    }
    else {
        printf("%s", str);
        for (int i = 0; i < bound - len; i++)
            printf(" ");
    }

    returning();
}

define_method(equals){
    param(Class, obj);

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
    param(Class, comp);

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
    param(Class, comp);

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
    returning(class, self->data);
}


/* END Dynamic initializer */

