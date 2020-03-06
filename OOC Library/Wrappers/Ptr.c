
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

void* Ptr_print(void* self, int bound){
    struct Ptr* _ptr = cast(Ptr(), self);

    if (bound < 5){
        printf("\nERROR: Cannot print with bound less than %i\n", 5);
        fflush(stdout);
        assert(0);
    }

    printf("|");

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
        // Print leading blank spaces
        for(int i = bound - digits - 2; i > 0; i--){
            printf(" ");
        }
        // Print number
        printf("0x");
        for(int i = digits-1; i >= 0; i--){
            if (arrData[i] < 10)
                printf("%i", arrData[i]);
            else
                printf("%c", arrData[i]-10 + 'a');
        }
    }

    printf("|\n");

    free(arrData);

    return NULL;
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
                         NULL));
}
/* END Dynamic initializer */
