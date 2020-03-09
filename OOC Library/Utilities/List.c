
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"
#include "List.r"


/** START Getters and Setters **/
object_build_getset()
/** END Getters and Setters **/

build_caller_funcs(get, set, remove, pop, clear, contains, indexOf, ofType)

/** START Caller functions **/
build_funcs(List,
            (get, (int, i)),
            (set, (int, i, void*, obj)),
            (remove, (int, i)),
            (push, (void*, obj)),
            (pop, (int, i)),
            (clear, ()),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(List, (),
                 (       (get, (int, i)),
                         (set, (int, i, void*, obj)),
                         (remove, (int, i)),
                         (pop, (int, i)),
                         (push, (void*, obj)),
                         (clear, ()),
                         (contains, (void*, obj)),
                         (indexOf, (void*, obj)),
                         (ofType, (void*, class))))


/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ListClass;

const void* const ListClass(){
    return _ListClass ? _ListClass :
           (_ListClass = new(Class(), "ListClass", Class(), sizeof(struct ListClass),
                               _ctor, ListClass_ctor,
                               NULL));
}

static const void* _List;

const void* const List(){
    return _List ? _List :
           (_List = new(ListClass(), "List", Object(), sizeof(struct List),
                          _get, abstract,
                          _set, abstract,
                          _remove, abstract,
                          _push, abstract,
                          _pop, abstract,
                          _clear, abstract,
                          _contains, abstract,
                          _indexOf, abstract,
                          _ofType, abstract,
                          NULL));
}
/* END Dynamic initializer */
