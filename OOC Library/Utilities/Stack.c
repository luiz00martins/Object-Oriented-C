
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Stack.h"
#include "Stack.r"


/** START Getters and Setters **/
object_build_getset()
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(Stack,
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(Stack, (),
                 (  (peek, ()),
                    (push, (void*, obj)),
                    (pop, ()),
                    (clear, ()),
                    (contains, (void*, obj)),
                    (indexOf, (void*, obj)),
                    (ofType, (void*, class))))


/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _StackClass;

const void* const StackClass(){
    return _StackClass ? _StackClass :
           (_StackClass = new(Class(), "StackClass", Class(), sizeof(struct StackClass),
                               _ctor, StackClass_ctor,
                               NULL));
}

static const void* _Stack;

const void* const Stack(){
    return _Stack ? _Stack :
           (_Stack = new(StackClass(), "Stack", Object(), sizeof(struct Stack),
                          _peek, abstract,
                          _push, abstract,
                          _pop, abstract,
                          _clear, abstract,
                          _contains, abstract,
                          _indexOf, abstract,
                          _ofType, abstract,
                          NULL));
}
/* END Dynamic initializer */
