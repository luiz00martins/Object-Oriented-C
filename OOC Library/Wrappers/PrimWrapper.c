
#include <assert.h>
#include <string.h>
#include "PrimWrapper.h"
#include "PrimWrapper.r"


/** START Getters and Setters **/

/** END Getters and Setters **/

/** START Caller functions **/
build_caller_funcs(scan, printBound)

build_funcs(PrimWrapper,
            (print, ()),
            (printBound, (int, bound)),
            (scan, ()))

/** END Caller functions **/


/** START Class method definitions **/
build_class_ctor(PrimWrapper,
                 (),
                 ((print, ()),
                  (printBound, (int, bound)),
                  (scan, ())))
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
    if(target) {
        void *dataPtr = (&primWrapper->_) + (((sizeOf(self) / 2) / sizeof(void *)));
        int size = as(int, dataSize(primWrapper));
        memcpy(dataPtr, target, size);
    }

    return self;
}
void* PrimWrapper_dtor(void* self){
    struct PrimWrapper* primWrapper = cast(PrimWrapper(), self);

    // Abstract class above
    //super_dtor(PrimWrapper(), primWrapper);

    return primWrapper;
}
void* PrimWrapper_unwrap(void* self, void* target){
    struct PrimWrapper* primWrapper = cast(PrimWrapper(), self);

    // This is divided by two, cus there's two variables in struct Wrapper, then by the number of bytes
    void* dataPtr = (&primWrapper->_) + (((sizeOf(self)/2)/sizeof(void*)));

    memcpy(target, dataPtr, as(int, dataSize(primWrapper)));

    return NULL;
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
                               _unwrap, PrimWrapper_unwrap,
                               _print, abstract,
                               _printBound, abstract,
                               _scan, abstract,
                               NULL));
}
/* END Dynamic initializer */
