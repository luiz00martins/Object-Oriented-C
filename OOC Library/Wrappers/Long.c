
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Long.h"
#include "Long.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* LongClass_ctor(void* self, va_list* args){
    struct LongClass* classPtr = super_ctor(LongClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Long, long, data);

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
void* Long_dataSize(const void* self){
    struct Long* _long = cast(Long(), self);

    int returned = sizeof(long);
    return returning(returned);
}

void* Long_print(void* self) {
    struct Long *_long = cast(Long(), self);

    printf("%li", _long->data);

    return NULL;
}

void* Long_printBound(void* self, int bound){
    struct Long* _long = cast(Long(), self);

    if (bound < 5){
        printf("\nERROR: Cannot print with bound less than %i\n", 5);
        fflush(stdout);
        assert(0);
    }

    printf("|");

    int digits = 1;
    long temp = _long->data;

    // Figuring out the number of digits
    while(temp >= 10){
        temp /= 10;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = _long->data;
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

    printf("|\n");

    free(arrData);

    return NULL;
}

void* Long_scan(void* self){
    struct Long* _long = cast(Long(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _long->data = strtol(arr, NULL, 10);

    return NULL;
}

void* Long_equals(void* self, void* obj){
    struct Long* _long = cast(Long(), self);

    bool returned = true;

    if(as(bool, super_equals(Long(), self, obj)))
        return returning(returned);

    struct Long* otherLong = cast(Long(), obj);

    if(_long->data == otherLong->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _LongClass;

const void* LongClass(){
    return _LongClass ? _LongClass :
           (_LongClass = new(PrimWrapperClass(), "LongClass", PrimWrapperClass(), sizeof(struct LongClass),
                             _ctor, LongClass_ctor,
                             NULL));
}

static const void* _Long;

const void* const Long(){
    return _Long ? _Long :
           (_Long = new(LongClass(), "Long", PrimWrapper(), sizeof(struct Long),
                         _dataSize, Long_dataSize,
                         _print, Long_print,
                         _printBound, Long_printBound,
                         _scan, Long_scan,
                         _equals, Long_equals,
                         NULL));
}
/* END Dynamic initializer */
