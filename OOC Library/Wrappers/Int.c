
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
const int Int_dataSize(const void* self){
    struct Int* _int = cast(Int(), self);;

    return sizeof(int);
}

/* Public: */

/* Protected: */

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
                           NULL));
}
/* END Dynamic initializer */
