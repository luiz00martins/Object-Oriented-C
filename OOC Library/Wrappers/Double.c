
#include <assert.h>
#include <stdlib.h>
#include <string.h>
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
const int Double_dataSize(const void* self){
    struct Double* _double = cast(Double(), self);;

    return sizeof(double);
}

/* Public: */

/* Protected: */

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
                         NULL));
}
/* END Dynamic initializer */
