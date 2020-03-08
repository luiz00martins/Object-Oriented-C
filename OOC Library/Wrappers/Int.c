
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Int.h"
#include "Int.r"

#include "../Object.h"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* IntClass_ctor(void* self, va_list* args){
    struct IntClass* classPtr = super_ctor(IntClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Int, int, data);

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
void* Int_dataSize(const void* self){
    struct Int* _int = cast(Int(), self);

    int returned = sizeof(long);
    return returning(returned);
}

void* Int_print(void* self) {
    struct Int *_int = cast(Int(), self);

    printf("%i", _int->data);

    return NULL;
}

void* Int_printBound(void* self, int bound){
    struct Int* _int = cast(Int(), self);

    if (bound < 5){
        printf("\nERROR: Cannot print with bound less than %i\n", 5);
        fflush(stdout);
        assert(0);
    }

    int digits = 1;
    int temp = _int->data;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = _int->data;
    for(int i = 0; i < digits; i++){
        arrData[i] = temp % 10;
        temp /= 10;
    }

    if(bound < digits){
        // Print all digits you can, but three, and print an ellipsis
        int notFit = 3 + digits - bound;
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
        for(int i = bound - digits; i > 0; i--){
            printf(" ");
        }
    }

    free(arrData);

    return NULL;
}

void* Int_scan(void* self){
    struct Int* _int = cast(Int(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _int->data = strtol(arr, NULL, 10);

    return NULL;
}

void* Int_equals(void* self, void* obj){
    struct Int* _int = cast(Int(), self);

    bool returned = true;

    if(as(bool, super_equals(Int(), self, obj)))
        return returning(returned);

    struct Int* otherInt = cast(Int(), obj);

    if(_int->data == otherInt->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _IntClass;

const void* IntClass(){
    return _IntClass ? _IntClass :
           (_IntClass = new(PrimWrapperClass(), "IntClass", PrimWrapperClass(), sizeof(struct IntClass),
                            _ctor, IntClass_ctor,
                            NULL));
}

static const void* _Int;

const void* const Int(){
    return _Int ? _Int :
           (_Int = new(IntClass(), "Int", PrimWrapper(), sizeof(struct Int),
                           _dataSize, Int_dataSize,
                           _print, Int_print,
                           _printBound, Int_printBound,
                           _scan, Int_scan,
                           _equals, Int_equals,
                           NULL));
}
/* END Dynamic initializer */
