#include <ctype.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Bool.h"
#include "Bool.r"

#define CLASS_NAME Bool 
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
    paramOptional(bool, val, false);

    self->data = val;
    returning(Bool, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(bool);
    returning(int, returned);
}

define_method(print){

    printf("%s", self->data ? "True" : "False");

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than 5\n");
    }

	char* str = self->data ? "True" : "False";
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

define_method(scan){
    char arr[100];
    scanf("%100s", arr);

    int i;
    for (i = 0; arr[i]; i++){
        arr[i] = tolower(arr[i]);
    }

    if (strcmp(arr, "true") || arr[0] == '1'){
        self->data = true;
    }
    else if (strcmp(arr, "false") || arr[0] == '0'){
        self->data = false;
    }
    
    returning();
}

define_method(equals){
    param(Bool, obj);

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
    param(Bool, comp);

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
    param(Bool, comp);

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
    returning(bool, self->data);
}


/* END Dynamic initializer */
