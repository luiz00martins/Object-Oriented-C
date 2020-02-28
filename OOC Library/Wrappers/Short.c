
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Short.h"
#include "Short.r"

/** START Getters and Setters **/
build_decl_get(data);
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* ShortClass_ctor(void* self, va_list* args){
    struct ShortClass* classPtr = super_ctor(ShortClass(), self, args);

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Short, short, data);

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
int Short_dataSize(void* self){
    struct Short* _short = cast(Short(), self);;

    return sizeof(short);
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ShortClass;

const void* ShortClass(){
    return _ShortClass ? _ShortClass :
           (_ShortClass = new(PrimWrapperClass(), "ShortClass", PrimWrapperClass(), sizeof(struct ShortClass),
                              _ctor, ShortClass_ctor,
                              NULL));
}

static const void* _Short;

const void* const Short(){
    return _Short ? _Short :
           (_Short = new(ShortClass(), "Short", PrimWrapper(), sizeof(struct Short),
                         _dataSize, Short_dataSize,
                         NULL));
}
/* END Dynamic initializer */
