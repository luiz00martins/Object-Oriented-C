
#include <assert.h>
#include <string.h>
#include "PrimWrapper.h"
#include "PrimWrapper.r"


/** START Static functions **/
int directDataSize(void* wrapper){
    cast(Wrapper(), &wrapper);
    return ((struct WrapperClass*)wrapper)->_dataSize(&wrapper);
}
/** END Static functions **/

/** START Getters and Setters **/

/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* PrimWrapperClass_ctor(void* self, va_list* args){
    struct PrimWrapperClass* classPtr = super_ctor(PrimWrapperClass(), self, args);
    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    va_copy(funcArgs, *args);
    /* Overloadable function setup. All functions that go here can be overloaded*/
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        //if (selector == func){
        //    classPtr->func = function;
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
void* PrimWrapper_ctor(void* self, va_list* args){
    // Calling super constructor
    struct PrimWrapper* primWrapper = cast(PrimWrapper(), self);

    // Abstract class above
    //super_ctor(PrimWrapper(), primWrapper);

    void* target = va_arg(*args, void*);

    // This is divided by two, cus there's two variables in struct Wrapper, then by the number of bytes
    void* dataPtr = (&primWrapper->_) + (((sizeOf(self)/2)/sizeof(void*)));

    memcpy(dataPtr, target, _dataSize(primWrapper));

    return self;
}
void* PrimWrapper_dtor(void* self){
    struct PrimWrapper* primWrapper = cast(PrimWrapper(), self);

    // Abstract class above
    //super_dtor(PrimWrapper(), primWrapper);

    return primWrapper;
}
void PrimWrapper__unwrap(void* target, const void* self){
    struct PrimWrapper* primWrapper = cast(PrimWrapper(), self);

    // This is divided by two, cus there's two variables in struct Wrapper, then by the number of bytes
    void* dataPtr = (&primWrapper->_) + (((sizeOf(self)/2)/sizeof(void*)));

    memcpy(target, dataPtr, _dataSize(primWrapper));

    return;
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _PrimWrapperClass;

const void* PrimWrapperClass(){
    return _PrimWrapperClass ? _PrimWrapperClass :
           (_PrimWrapperClass = new(WrapperClass(), "PrimWrapperClass", WrapperClass(), sizeof(struct PrimWrapperClass),
                                    _ctor, PrimWrapperClass_ctor,
                                    NULL));
}

static const void* _PrimWrapper;

const void* const PrimWrapper(){
    return _PrimWrapper ? _PrimWrapper :
           (_PrimWrapper = new(PrimWrapperClass(), "PrimWrapper", Wrapper(), sizeof(struct PrimWrapper),
                               _ctor, PrimWrapper_ctor,
                               _dtor, PrimWrapper_dtor,
                               _unwrap, PrimWrapper__unwrap,
                               NULL));
}
/* END Dynamic initializer */
