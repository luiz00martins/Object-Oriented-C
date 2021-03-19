#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Pointer.h"
#include "Pointer.r"

#define CLASS_NAME Pointer 
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
    paramOptional(pointer, val, NULL);

    self->data = val;

    returning(Pointer, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(pointer);
    returning(int, returned);
}

define_method(print){

    printf("%p", self->data);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than %i\n");
    }

    int digits = 1;
    long long temp = (long long)self->data;

    // Figuring out the number of digits
    while(temp >= 16){
        temp = temp / 16;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = (long long)self->data;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 16;
        temp /= 16;
    }

    if(bound < digits+2){
        // Print all digits you can, but three, and print an ellipsis
        int notFit = 5 + digits - bound;
        printf("0x");
        for(int i = digits-1; i >= notFit; i--){
            if (arrData[i] < 10)
                printf("%i", arrData[i]);
            else
                printf("%c", arrData[i]-10 + 'a');
        }
        printf("...");
    }
    else {
        // Print number
        printf("0x");
        for(int i = digits-1; i >= 0; i--){
            if (arrData[i] < 10)
                printf("%i", arrData[i]);
            else
                printf("%c", arrData[i]-10 + 'a');
        }
        // Print blank spaces
        for(int i = bound - digits - 2; i > 0; i--){
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
    self->data = (pointer)strtol(arr, NULL, 16);

    returning();
}

define_method(equals){
    param(Pointer, obj);

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
    param(Pointer, comp);

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
    param(Pointer, comp);

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
    returning(pointer, self->data);
}


/* END Dynamic initializer */
