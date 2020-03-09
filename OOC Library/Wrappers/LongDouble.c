
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "LongDouble.h"
#include "LongDouble.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* LongDoubleClass_ctor(void* self, va_list* args){
    struct LongDoubleClass* classPtr = super_ctor(LongDoubleClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(LongDouble, long double, data);

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
void* LongDouble_dataSize(const void* self){
    struct LongDouble* _longDouble = cast(LongDouble(), self);;

    int returned = sizeof(long double);
    return returning(returned);
}

void* LongDouble_print(void* self) {
    struct LongDouble *_longDouble = cast(LongDouble(), self);

    printf("%Lf", _longDouble->data);

    return NULL;
}

void* LongDouble_printBound(void* self, int bound){
    struct LongDouble* _longDouble = cast(LongDouble(), self);

    int digits = 1;
    long long temp;
    temp = _longDouble->data < 0 ? _longDouble->data * 10000000 * -1 : _longDouble->data * 10000000;
    temp /= 10;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    int* arrData = malloc(sizeof(int) * digits);

    // Separating the digits;
    temp = _longDouble->data < 0 ? _longDouble->data * 10000000 * -1 : _longDouble->data * 10000000;
    temp /= 10;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    int overhead = (digits <= 6? 2 : 0) + (_longDouble->data < 0 ? 1 : 0);

    if (_longDouble->data < 0)
        printf("-");
    if(bound < digits+overhead || bound < 8){
        // Print all digits you can, but three, and print an ellipsis
        int leftSpaces = bound - 4;
        if (_longDouble->data < 0) leftSpaces--;
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
        if(_longDouble->data < 0) whiteSpaces--;
        for(int i = 0; i < whiteSpaces; i++)
            printf(" ");
    }

    free(arrData);

    return NULL;
}

void* LongDouble_scan(void* self){
    struct LongDouble* _longDouble = cast(LongDouble(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _longDouble->data = strtold(arr, NULL);

    return NULL;
}

void* LongDouble_equals(void* self, void* obj){
    struct LongDouble* _longDouble = cast(LongDouble(), self);

    bool returned = true;

    if(as(bool, super_equals(LongDouble(), self, obj)))
        return returning(returned);

    struct LongDouble* otherLongDouble = cast(LongDouble(), obj);

    if(_longDouble->data == otherLongDouble->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _LongDoubleClass;

const void* LongDoubleClass(){
    return _LongDoubleClass ? _LongDoubleClass :
           (_LongDoubleClass = new(PrimWrapperClass(), "LongDoubleClass", PrimWrapperClass(),
                                   sizeof(struct LongDoubleClass),
                                   _ctor, LongDoubleClass_ctor,
                                   NULL));
}

static const void* _LongDouble;

const void* const LongDouble(){
    return _LongDouble ? _LongDouble :
           (_LongDouble = new(LongDoubleClass(), "LongDouble", PrimWrapper(), sizeof(struct LongDouble),
                         _dataSize, LongDouble_dataSize,
                         _print, LongDouble_print,
                         _printBound, LongDouble_printBound,
                         _scan, LongDouble_scan,
                         _equals, LongDouble_equals,
                         NULL));
}
/* END Dynamic initializer */
