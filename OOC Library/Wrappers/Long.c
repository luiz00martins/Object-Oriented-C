
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
const int Long_dataSize(const void* self){
    struct Long* _long = cast(Long(), self);;

    return sizeof(long);
}

/* Public: */

/* Protected: */

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
                         NULL));
}
/* END Dynamic initializer */
