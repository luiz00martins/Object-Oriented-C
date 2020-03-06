
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"
#include "Queue.r"


/** START Getters and Setters **/
object_build_getset()
/** END Getters and Setters **/

build_caller_funcs(peek, push)

/** START Caller functions **/
build_funcs(Queue,
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(Queue, (),
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
static const void* _QueueClass;

const void* const QueueClass(){
    return _QueueClass ? _QueueClass :
           (_QueueClass = new(Class(), "QueueClass", Class(), sizeof(struct QueueClass),
                               _ctor, QueueClass_ctor,
                               NULL));
}

static const void* _Queue;

const void* const Queue(){
    return _Queue ? _Queue :
           (_Queue = new(QueueClass(), "Queue", Object(), sizeof(struct Queue),
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
