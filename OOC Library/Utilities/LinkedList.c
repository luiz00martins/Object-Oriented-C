
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"
#include "LinkedList.r"


/** START Getters and Setters **/
object_build_getset(nodes)
build_decl_get(len);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(LinkedList,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (get, (int, i)),
            (set, (int, i, void*, obj)),
            (remove, (int, i)),
            (pop, (int, i)),
            (clear, ()),
            (resize, (int, size)),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedList,
                 ((void**, nodes), (int, len)),
                 ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedList_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_ctor(LinkedList(), self, args);


    return self;
}
void* LinkedList_dtor(void* self){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_dtor(LinkedList(), self);



    return self;
}
void* LinkedList_get(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_get(LinkedList(), self, i);



    return NULL;
}
void* LinkedList_set(void* self, int i, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_set(LinkedList(), self, i, obj);



    return NULL;
}
void* LinkedList_remove(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_remove(LinkedList(), self, i);



    return NULL;
}
void* LinkedList_pop(void* self, int i){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_pop(LinkedList(), self, i);



    return NULL;
}
void* LinkedList_clear(void* self){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_clear(LinkedList(), self);



    return NULL;
}
void* LinkedList_resize(void* self, int size){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_resize(LinkedList(), self, size);



    return NULL;
}
void* LinkedList_contains(void* self, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_contains(LinkedList(), self, obj);



    return NULL;
}
void* LinkedList_indexOf(void* self, void* obj){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_indexOf(LinkedList(), self, obj);



    return NULL;
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _LinkedListClass;

const void* const LinkedListClass(){
    return _LinkedListClass ? _LinkedListClass :
           (_LinkedListClass = new(ListClass(), "LinkedListClass", ListClass(), sizeof(struct LinkedListClass),
                                  _ctor, LinkedListClass_ctor,
                                  NULL));
}

static const void* _LinkedList;

const void* const LinkedList(){
    return _LinkedList ? _LinkedList :
           (_LinkedList = new(LinkedListClass(), "LinkedList", List(), sizeof(struct LinkedList),
                             _ctor, LinkedList_ctor,
                             _dtor, LinkedList_dtor,
                             _get, LinkedList_get,
                             _set, LinkedList_set,
                             _remove, LinkedList_remove,
                             _pop, LinkedList_pop,
                             _clear, LinkedList_clear,
                             _resize, LinkedList_resize,
                             _contains, LinkedList_contains,
                             _indexOf, LinkedList_indexOf,
                             NULL));
}
/* END Dynamic initializer */
