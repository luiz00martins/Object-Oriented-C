
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayList.h"
#include "ArrayList.r"


/** START Getters and Setters **/
object_build_getset(objs, type)
build_decl_get(len);
build_decl_get(size);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(ArrayList,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (get, (int, i)),
            (set, (int, i, void*, obj)),
            (remove, (int, i)),
            (pop, (int, i)),
            (clear, ()),
            (resize, (int, size)),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(ArrayList,
        ((void**, objs), (int, len), (int, size), (struct Class*, type)),
        ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* ArrayList_ctor(void* self, va_list* args){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_ctor(ArrayList(), self, args);

    // Gathering arguments
    arrayList->type = va_arg(*args, void*);

    arrayList->size = 1;
    arrayList->len = 0;
    arrayList->objs = malloc(sizeof(void*));

    return self;
}
void* ArrayList_dtor(void* self){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_dtor(ArrayList(), self);

    free(arrayList->objs);

    return self;
}
void* ArrayList_get(void* self, int i){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_get(ArrayList(), self, i);



    return NULL;
}
void* ArrayList_set(void* self, int i, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_set(ArrayList(), self, i, obj);



    return NULL;
}
void* ArrayList_remove(void* self, int i){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_remove(ArrayList(), self, i);



    return NULL;
}
void* ArrayList_pop(void* self, int i){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_pop(ArrayList(), self, i);


    return NULL;
}
void* ArrayList_clear(void* self){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_clear(ArrayList(), self);



    return NULL;
}
void* ArrayList_resize(void* self, int size){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_resize(ArrayList(), self, size);



    return NULL;
}
void* ArrayList_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_contains(ArrayList(), self, obj);



    return NULL;
}
void* ArrayList_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_indexOf(ArrayList(), self, obj);



    return NULL;
}
// TODO: Push this to List, maybe to the not yet build "Collection"
void* ArrayList_ofType(void* self, void* class){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_ofType(ArrayList(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(arrayList->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ArrayListClass;

const void* const ArrayListClass(){
    return _ArrayListClass ? _ArrayListClass :
           (_ArrayListClass = new(ListClass(), "ArrayListClass", ListClass(), sizeof(struct ArrayListClass),
                               _ctor, ArrayListClass_ctor,
                               NULL));
}

static const void* _ArrayList;

const void* const ArrayList(){
    return _ArrayList ? _ArrayList :
           (_ArrayList = new(ArrayListClass(), "ArrayList", List(), sizeof(struct ArrayList),
                          _ctor, ArrayList_ctor,
                          _dtor, ArrayList_dtor,
                          _get, ArrayList_get,
                          _set, ArrayList_set,
                          _remove, ArrayList_remove,
                          _pop, ArrayList_pop,
                          _clear, ArrayList_clear,
                          _resize, ArrayList_resize,
                          _contains, ArrayList_contains,
                          _indexOf, ArrayList_indexOf,
                          _ofType, ArrayList_ofType,
                          NULL));
}
/* END Dynamic initializer */
