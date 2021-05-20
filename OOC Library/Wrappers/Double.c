#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Double.h"
#include "Double.r"

#define CLASS_NAME Double
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
    paramOptional(double, val, 0);

    self->data = val;
    returning(Double, self);
}


/* Overloaded: */
define_method(dataSize){

    int returned = sizeof(double);
    returning(int, returned);
}

define_method(print){

    printf("%lf", self->data);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < 5){
        error("\nERROR: Cannot print with bound less than 5\n");
    }

    int digits = 1;
    long long temp;
    temp = self->data < 0 ? self->data * 10000000 * -1 : self->data * 10000000;
    temp /= 10;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    int* arrData = malloc(sizeof(int) * digits);

    // Separating the digits;
    temp = self->data < 0 ? self->data * 10000000 * -1 : self->data * 10000000;
    temp /= 10;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    int overhead = (digits <= 6? 2 : 1) + (self->data < 0 ? 1 : 0);

    if (self->data < 0)
        printf("-");
    if(bound < digits+overhead || bound < 8){
        // Print all digits you can, but three, and print an ellipsis
        int leftSpaces = bound - 4;
        if (self->data < 0) leftSpaces--;
        if(digits <= 6) {
            printf("0");
            leftSpaces--;
        }
        int i;
        for(i = digits-1; i > 5 && leftSpaces > 0; i--, leftSpaces--){
            printf("%i", arrData[i]);
        }
        printf(".");
        for(int j = i; j < 5 && leftSpaces > 0; j++, leftSpaces--) {
            printf("0");
        }
        for(;i >= 0 && leftSpaces > 0; i--, leftSpaces--){
            printf("%i", arrData[i]);
        }
        printf("...");
    }
    else{
        // Print a zero if there's no digit to print
        if(digits <= 6)
            printf("0");
        int i;
        // Print digits before ".", if there's any
        for(i = digits-1; i > 5; i--){
            printf("%i", arrData[i]);
        }
        printf(".");
        // Print zeros, in case there's not enough digits
        for(int j = i; j < 5; j++)
            printf("0");
        // Print digits after "."
        for(;i >= 0; i--){
            printf("%i", arrData[i]);
        }
        int whiteSpaces = bound - (digits > 7 ? digits : 7) - 1;
        if(self->data < 0.0) whiteSpaces--;
        for(int i = 0; i < whiteSpaces; i++)
            printf(" ");
    }

    free(arrData);

    returning();
}

define_method(scan){

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    self->data = strtod(arr, NULL);

    returning();
}

define_method(equals){
    param(Double, obj);

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
    param(Double, comp);

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
    param(Double, comp);

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
    returning(double, self->data);
}


/* END Dynamic initializer */
