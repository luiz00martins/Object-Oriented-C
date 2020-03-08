
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Ptr.h"
#include "Ptr.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* PtrClass_ctor(void* self, va_list* args){
    struct PtrClass* classPtr = super_ctor(PtrClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Ptr, void*, data);

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
void* Ptr_dataSize(const void* self){
    struct Ptr* _ptr = cast(Ptr(), self);

    int returned = sizeof(void*);
    return returning(returned);
}

void* Ptr_print(void* self) {
    struct Ptr *_ptr = cast(Ptr(), self);

    printf("%p", _ptr->data);

    return NULL;
}

void* Ptr_printBound(void* self, int bound){
    struct Ptr* _ptr = cast(Ptr(), self);

    if (bound < 5){
        printf("\nERROR: Cannot print with bound less than %i\n", 5);
        fflush(stdout);
        assert(0);
    }

    int digits = 1;
    long long temp = (long long)_ptr->data;

    // Figuring out the number of digits
    while(temp >= 16){
        temp = temp / 16;
        digits++;
    }

    // Separating the digits;
    int* arrData = malloc(sizeof(int) * digits);
    temp = (long long)_ptr->data;
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

    return NULL;
}

void* Ptr_scan(void* self){
    struct Ptr* _ptr = cast(Ptr(), self);

    char arr[100];
    char c;
    scanf("%100s%c", arr, &c);
    _ptr->data = strtol(arr, NULL, 16);

    return NULL;
}

void* Ptr_equals(void* self, void* obj){
    struct Ptr* _ptr = cast(Ptr(), self);

    bool returned = true;

    if(as(bool, super_equals(Ptr(), self, obj)))
        return returning(returned);

    struct Ptr* otherPtr = cast(Ptr(), obj);

    if(_ptr->data == otherPtr->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _PtrClass;

const void* PtrClass(){
    return _PtrClass ? _PtrClass :
           (_PtrClass = new(PrimWrapperClass(), "PtrClass", PrimWrapperClass(), sizeof(struct PtrClass),
                            _ctor, PtrClass_ctor,
                            NULL));
}

static const void* _Ptr;

const void* const Ptr(){
    return _Ptr ? _Ptr :
           (_Ptr = new(PtrClass(), "Ptr", PrimWrapper(), sizeof(struct Ptr),
                         _dataSize, Ptr_dataSize,
                         _print, Ptr_print,
                         _printBound, Ptr_printBound,
                         _scan, Ptr_scan,
                         _equals, Ptr_equals,
                         NULL));
}
/* END Dynamic initializer */
