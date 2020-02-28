
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "LongLong.h"
#include "LongLong.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* LongLongClass_ctor(void* self, va_list* args){
    struct LongLongClass* classPtr = super_ctor(LongLongClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(LongLong, long long, data);

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
const int LongLong_dataSize(const void* self){
    struct LongLong* _longLong = cast(LongLong(), self);;

    return sizeof(float);
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _LongLongClass;

const void* LongLongClass(){
    return _LongLongClass ? _LongLongClass :
           (_LongLongClass = new(PrimWrapperClass(), "LongLongClass", PrimWrapperClass(), sizeof(struct LongLongClass),
                                 _ctor, LongLongClass_ctor,
                                 NULL));
}

static const void* _LongLong;

const void* const LongLong(){
    return _LongLong ? _LongLong :
           (_LongLong = new(LongLongClass(), "LongLong", PrimWrapper(), sizeof(struct LongLong),
                         _dataSize, LongLong_dataSize,
                         NULL));
}
/* END Dynamic initializer */
