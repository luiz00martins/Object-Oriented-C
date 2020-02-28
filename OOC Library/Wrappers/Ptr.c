
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
const int Ptr_dataSize(const void* self){
    struct Ptr* _ptr = cast(Ptr(), self);;

    return sizeof(void*);
}

/* Public: */

/* Protected: */

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
                         NULL));
}
/* END Dynamic initializer */
