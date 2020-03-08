
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Float.h"
#include "Float.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* FloatClass_ctor(void* self, va_list* args){
    struct FloatClass* classPtr = super_ctor(FloatClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Float, float, data);

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
void* Float_dataSize(const void* self){
    struct Float* _float = cast(Float(), self);

    int returned = sizeof(float);
    return returning(returned);
}

void* Float_print(void* self) {
    struct Float *_float = cast(Float(), self);

    printf("%f", _float->data);

    return NULL;
}

void* Float_printBound(void* self, int bound){
    struct Float* _float = cast(Float(), self);

    int digits = 1;
    long long temp;
    temp = _float->data < 0 ? _float->data * 10000000 * -1 : _float->data * 10000000;
    temp /= 10;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    int* arrData = malloc(sizeof(int) * digits);

    // Separating the digits;
    temp = _float->data < 0 ? _float->data * 10000000 * -1 : _float->data * 10000000;
    temp /= 10;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    int overhead = digits <= 6? 2 : 0 + _float->data < 0 ? 1 : 0;

    if (_float->data < 0)
        printf("-");
    if(bound < digits+overhead || bound < 8){
        // Print all digits you can, but three, and print an ellipsis
        int leftSpaces = bound - 4;
        if (_float->data < 0) leftSpaces--;
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
        if(_float->data < 0) whiteSpaces--;
        for(int i = 0; i < whiteSpaces; i++)
            printf(" ");
    }

    free(arrData);

    return NULL;
}

void* Float_scan(void* self){
    struct Float* _float = cast(Float(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _float->data = strtof(arr, NULL);

    return NULL;
}

void* Float_equals(void* self, void* obj){
    struct Float* _float = cast(Float(), self);

    bool returned = true;

    if(as(bool, super_equals(Float(), self, obj)))
        return returning(returned);

    struct Float* otherFloat = cast(Float(), obj);

    if(_float->data == otherFloat->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _FloatClass;

const void* FloatClass(){
    return _FloatClass ? _FloatClass :
           (_FloatClass = new(PrimWrapperClass(), "FloatClass", PrimWrapperClass(), sizeof(struct FloatClass),
                              _ctor, FloatClass_ctor,
                              NULL));
}

static const void* _Float;

const void* const Float(){
    return _Float ? _Float :
           (_Float = new(FloatClass(), "Float", PrimWrapper(), sizeof(struct Float),
                        _dataSize, Float_dataSize,
                        _print, Float_print,
                        _printBound, Float_printBound,
                        _scan, Float_scan,
                        _equals, Float_equals,
                        NULL));
}
/* END Dynamic initializer */
