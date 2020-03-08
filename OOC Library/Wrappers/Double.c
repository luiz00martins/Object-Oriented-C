
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Double.h"
#include "Double.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* DoubleClass_ctor(void* self, va_list* args){
    struct DoubleClass* classPtr = super_ctor(DoubleClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Double, double, data);

    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    va_copy(funcArgs, *args);
    /* Overloadable function setup. All functions that go here can be overloaded*/
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        //if (selector == dataSize){
        //    classPtr->dataSize = function;
        //}
    }
    va_end(funcArgs);

    if (false /* classPtr->func == abstract */ ){

        struct Class* class = classPtr;
        class->abstract = true;
    }

    return self;
}
/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* Double_dataSize(const void* self){
    struct Double* _double = cast(Double(), self);;

    int returned = sizeof(double);
    return returning(returned);
}

void* Double_print(void* self) {
    struct Double *_double = cast(Double(), self);

    printf("%lf", _double->data);

    return NULL;
}

void* Double_printBound(void* self, int bound){
    struct Double* _double = cast(Double(), self);

    int digits = 1;
    long long temp;
    temp = _double->data < 0 ? _double->data * 10000000 * -1 : _double->data * 10000000;
    temp /= 10;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    int* arrData = malloc(sizeof(int) * digits);

    // Separating the digits;
    temp = _double->data < 0 ? _double->data * 10000000 * -1 : _double->data * 10000000;
    temp /= 10;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    int overhead = digits <= 6? 2 : 0 + _double->data < 0 ? 1 : 0;

    if (_double->data < 0)
        printf("-");
    if(bound < digits+overhead || bound < 8){
        // Print all digits you can, but three, and print an ellipsis
        int leftSpaces = bound - 4;
        if (_double->data < 0) leftSpaces--;
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
        // Print a zerot if there's no digit to print
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
        int whiteSpaces = bound - (digits > 8? digits : 8) - 1;
        if(_double->data < 0) whiteSpaces--;
        for(int i = 0; i < whiteSpaces; i++)
            printf(" ");
    }

    free(arrData);

    return NULL;
}

void* Double_scan(void* self){
    struct Double* _double = cast(Double(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _double->data = strtod(arr, NULL);

    return NULL;
}

void* Double_equals(void* self, void* obj){
    struct Double* _double = cast(Double(), self);

    bool returned = true;

    if(as(bool, super_equals(Double(), self, obj)))
        return returning(returned);

    struct Double* otherDouble = cast(Double(), obj);

    if(_double->data == otherDouble->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _DoubleClass;

const void* DoubleClass(){
    return _DoubleClass ? _DoubleClass :
           (_DoubleClass = new(PrimWrapperClass(), "DoubleClass", PrimWrapperClass(), sizeof(struct DoubleClass),
                               _ctor, DoubleClass_ctor,
                               NULL));
}

static const void* _Double;

const void* const Double(){
    return _Double ? _Double :
           (_Double = new(DoubleClass(), "Double", PrimWrapper(), sizeof(struct Double),
                         _dataSize, Double_dataSize,
                         _print, Double_print,
                         _printBound, Double_printBound,
                         _scan, Double_scan,
                         _equals, Double_equals,
                         NULL));
}
/* END Dynamic initializer */
