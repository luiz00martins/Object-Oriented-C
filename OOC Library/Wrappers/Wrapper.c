
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
single_build_func(Wrapper, dataSize, (int*, target))
single_build_func(Wrapper, unwrap, (void*, target, int, targetSize))
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
void* WrapperClass_ctor(void* self, va_list* args){
    struct WrapperClass* classPtr = super_ctor(WrapperClass(), self, args);
    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    classPtr->_dataSize = _dataSize;
    classPtr->caller_dataSize = caller_Wrapper_dataSize;
    classPtr->_unwrap = _unwrap;
    classPtr->caller_unwrap = caller_Wrapper_unwrap;

    va_copy(funcArgs, *args);
    /* Overloadable function setup. All functions that go here can be overloaded*/
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        if (selector == _dataSize){
            classPtr->this_dataSize = function;
        }
        if (selector == _unwrap){
            classPtr->this_unwrap = function;
        }
    }
    va_end(funcArgs);

    if (classPtr->this_dataSize == abstract ||
        classPtr->this_unwrap == abstract){

        struct Class* class = classPtr;
        class->abstract = true;
    }

    return self;
}
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
