
#include <stdlib.h>
#include <assert.h>
#include <string.h>
#include "Struct.h"
#include "Struct.r"

/** START Getters and Setters **/
build_decl_get(size);
object_build_getset(dataPtr)
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* StructClass_ctor(void* self, va_list* args){
    struct StructClass* classPtr = super_ctor(StructClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Struct, void*, dataPtr)
    single_addVar(Struct, int, size)

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
void* Struct_ctor(void* self, va_list* args){
    struct Struct* _struct = cast(Struct(), self);

    // Abstract class above
    //super_ctor(StructClass(), self, args);

    void* targetPtr = va_arg(*args, void*);
    _struct->size = va_arg(*args, int);

    // Allocations:
    _struct->dataPtr = malloc(_struct->size);

    memcpy(_struct->dataPtr, targetPtr, _struct->size);

    return self;
}
void* Struct_dtor(const void* self){
    // Calling super destructor
    struct Struct* _struct = cast(Struct(), self);

    // Abstract class above
    //super_dtor(StructClass(), self);

    // Deallocations:
    free(_struct->dataPtr);

    return self;
}
void* Struct_unwrap(void* self, void* target){
    struct Struct* _struct = cast(Struct(), self);

    // Abstract class above
    //super__unwrap(StructClass(), self, args);

    memcpy(target, _struct->dataPtr, _struct->size);

    return NULL;
}
void* Struct_dataSize(void* self){
    struct Struct* _struct = cast(Struct(), self);

    // Abstract class above
    //super_dataSize(StructClass(), self);


    return returning(_struct->size);
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _StructClass;

const void* StructClass(){
    return _StructClass ? _StructClass :
           (_StructClass = new(WrapperClass(), "StructClass", WrapperClass(), sizeof(struct StructClass),
                               _ctor, StructClass_ctor,
                               NULL));
}

static const void* _Struct;

const void* const Struct(){
    return _Struct ? _Struct :
           (_Struct = new(StructClass(), "Struct", Wrapper(), sizeof(struct Struct),
                          _ctor, Struct_ctor,
                          _dtor, Struct_dtor,
                          _dataSize, Struct_dataSize,
                          _unwrap, Struct_unwrap,
                          NULL));
}
/* END Dynamic initializer */
