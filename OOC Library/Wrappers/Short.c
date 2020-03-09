
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Short.h"
#include "Short.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* ShortClass_ctor(void* self, va_list* args){
    struct ShortClass* classPtr = super_ctor(ShortClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Short, short, data);

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
void* Short_dataSize(void* self){
    struct Short* _short = cast(Short(), self);

    int returned = sizeof(short);
    return returning(returned);
}

void* Short_print(void* self) {
    struct Short *_short = cast(Short(), self);

    printf("%hi", _short->data);

    return NULL;
}

void* Short_printBound(void* self, int bound){
    struct Short* _short = cast(Short(), self);

    if (bound < 5){
        printf("\nERROR: Cannot print with bound less than %i\n", 5);
        fflush(stdout);
        assert(0);
    }

    int digits = 1;
    short temp = _short->data < 0 ? _short->data * -1 : _short->data;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = _short->data < 0 ? _short->data * -1 : _short->data;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    if (_short->data < 0) printf("-");
    if(bound < digits){
        // Print all digits you can, but three, and print an ellipsis
        int notFit = 3 + digits - bound - _short->data < 0 ? 1 : 0;
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
        for(i = bound - digits - (_short->data < 0 ? 1 : 0); i > 0; i--){
            printf(" ");
        }
    }

    free(arrData);

    return NULL;
}

void* Short_scan(void* self){
    struct Short* _short = cast(Short(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _short->data = strtol(arr, NULL, 10);

    return NULL;
}

void* Short_equals(void* self, void* obj){
    struct Short* _short = cast(Short(), self);

    bool returned = true;

    if(as(bool, super_equals(Short(), self, obj)))
        return returning(returned);

    struct Short* otherShort = cast(Short(), obj);

    if(_short->data == otherShort->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ShortClass;

const void* ShortClass(){
    return _ShortClass ? _ShortClass :
           (_ShortClass = new(PrimWrapperClass(), "ShortClass", PrimWrapperClass(), sizeof(struct ShortClass),
                              _ctor, ShortClass_ctor,
                              NULL));
}

static const void* _Short;

const void* const Short(){
    return _Short ? _Short :
           (_Short = new(ShortClass(), "Short", PrimWrapper(), sizeof(struct Short),
                         _dataSize, Short_dataSize,
                         _print, Short_print,
                         _printBound, Short_printBound,
                         _scan, Short_scan,
                         _equals, Short_equals,
                         NULL));
}
/* END Dynamic initializer */
