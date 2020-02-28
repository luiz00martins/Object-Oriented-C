
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
const int LongDouble_dataSize(const void* self){
    struct LongDouble* _longDouble = cast(LongDouble(), self);;

    return sizeof(long double);
}

/* Public: */

/* Protected: */

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
                         NULL));
}
/* END Dynamic initializer */
