#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Short.h"
#include "Short.r"

#define CLASS_NAME Short
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


/** START Class method definitions **/
define_method(ctor){
    paramOptional(short, val, 0);

    self->data = val;

    returning(Short, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(short);
    returning(int, returned);
}

define_method(print){

    printf("%hi", self->data);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than %i\n");
    }

    int digits = 1;
    short temp = self->data < 0 ? self->data * -1 : self->data;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = self->data < 0 ? self->data * -1 : self->data;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    if (self->data < 0) printf("-");
    if(bound < digits){
        // Print all digits you can, but three, and print an ellipsis
        int notFit = 3 + digits - bound - self->data < 0 ? 1 : 0;
        for(int i = digits-1; i >= notFit; i--){
            printf("%i", arrData[i]);
        }
        printf("...");
    }
    else {
        // Print number
        for(int i = digits-1; i >= 0; i--){
            printf("%i", arrData[i]);
        }
        // Print blank spaces
        int i;
        for(i = bound - digits - (self->data < 0 ? 1 : 0); i > 0; i--){
            printf(" ");
        }
    }

    free(arrData);

    returning();
}

define_method(scan){

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    self->data = strtol(arr, NULL, 10);

    returning();
}

define_method(equals){
    param(Short, obj);

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
    param(Short, comp);

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
    param(Short, comp);

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
    returning(short, self->data);
}


/* END Dynamic initializer */
