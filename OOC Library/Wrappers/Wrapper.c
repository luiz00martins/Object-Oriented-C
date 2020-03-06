
#include <assert.h>
#include <string.h>
#include "Wrapper.h"
#include "Wrapper.r"

/** START Getters and Setters **/

/** END Getters and Setters **/

single_build_caller_funcs(dataSize)
single_build_caller_funcs(unwrap)

/** START Caller functions **/
/* Public callers */
single_build_func(Wrapper, dataSize, ())
single_build_func(Wrapper, unwrap, (void*, target))
//object_builder_caller(const int, dataSize, (const void* self), (self))

//single_object_build_super_caller(void, unwrap, (const struct Class* class, void* target, const void* self), (target, self))
/** END Caller functions **/

int arrayPtrSize(void** ptr){
    int i;

    for (i = 0; ptr[i] != NULL; i++);
    i++;

    return i;
}

/** START Class method definitions **/
build_class_ctor(Wrapper,
                 (),
                 ((dataSize, ()),
                  (unwrap, (void*, target))))
/** END Class method definitions **/

#define object_build_abtract_method(TYPE, FUNC, TYPED_ARGS) \
    TYPE Abstract_Wrapper_##FUNC TYPED_ARGS{ \
        cast(Wrapper(), self); \
     \
    assert(0 /* Cannot construct abtract objects. Dot not call its super */); \
     \
    return 0; \
    }
#define void_object_build_abtract_method(TYPE, FUNC, TYPED_ARGS) \
    TYPE Abstract_Wrapper_##FUNC TYPED_ARGS{ \
        cast(Wrapper(), self); \
     \
    assert(0 /* Cannot construct abtract objects. Dot not call its super */); \
     \
    return; \
    }
/** START Object method definitions **USER CODE** **/
/* Overloaded: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _WrapperClass;

const void* WrapperClass(){
    return _WrapperClass ? _WrapperClass :
           (_WrapperClass = new(Class(), "WrapperClass", Class(), sizeof(struct WrapperClass),
                                _ctor, WrapperClass_ctor,
                                NULL));
}

static const void* _Wrapper;

const void* const Wrapper(){
    return _Wrapper ? _Wrapper :
           (_Wrapper = new(WrapperClass(), "Wrapper", Object(), sizeof(struct Wrapper),
                           _ctor, abstract,
                           _dataSize, abstract,
                           _unwrap, abstract,
                           NULL));
}
/* END Dynamic initializer */
