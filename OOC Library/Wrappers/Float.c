
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Float.h"
#include "Float.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* FloatClass_ctor(void* self, va_list* args){
    struct FloatClass* classPtr = super_ctor(FloatClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Float, float, data);

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
void* Float_dataSize(const void* self){
    struct Float* _float = cast(Float(), self);;

    int returned = sizeof(float);
    return returning(returned);
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _FloatClass;

const void* FloatClass(){
    return _FloatClass ? _FloatClass :
           (_FloatClass = new(PrimWrapperClass(), "FloatClass", PrimWrapperClass(), sizeof(struct FloatClass),
                              _ctor, FloatClass_ctor,
                              NULL));
}

static const void* _Float;

const void* const Float(){
    return _Float ? _Float :
           (_Float = new(FloatClass(), "Float", PrimWrapper(), sizeof(struct Float),
                        _dataSize, Float_dataSize,
                        NULL));
}
/* END Dynamic initializer */
