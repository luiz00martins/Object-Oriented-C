
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayList.h"
#include "ArrayList.r"
#include "../Wrappers/PrimWrapper.h"


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
            (add, (int, i, void*, obj)),
            (remove, (int, i)),
            (pop, (int, i)),
            (clear, ()),
            (resize, (int, size)),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)),
            (print, (int, bound)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(ArrayList,
        ((void**, objs), (int, len), (int, size), (struct Class*, type)),
        ((resize, (int, size)),
         (print, (int, bound))))

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


    if(i < 0 || i >= arrayList->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    return arrayList->objs[i];
}
void* ArrayList_add(void* self, int i, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_add(ArrayList(), self, i, obj);

    if(i < 0){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    if(i > arrayList->len){
        i = arrayList->len;
    }

    if(arrayList->len == arrayList->size){
        resize(arrayList, arrayList->size * 2);
    }

    /*if(arrayList->objs[i] == NULL){
        arrayList->objs[i] = obj;
    }*/
    int cont;
    for(cont = arrayList->len; cont > i; cont--){
        arrayList->objs[cont] = arrayList->objs[cont-1];
    }

    arrayList->objs[i] = obj;
    (arrayList->len)++;

    return NULL;
}
void* ArrayList_remove(void* self, int i){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);

    if(i < 0 || i > arrayList->len) return NULL;

    int cont;
    for(cont = i; cont < arrayList->len; cont++){
        arrayList->objs[cont] = arrayList->objs[cont+1];
    }
    arrayList->len--;

    return NULL;
}
void* ArrayList_push(void* self, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);

    add(arrayList, arrayList->len, obj);

    return NULL;
}
void* ArrayList_pop(void* self, int i){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_pop(ArrayList(), self, i);

    if(i < 0 || i >= arrayList->len){
        printf("\nERROR: List index out of bounds\n");
        fflush(stdout);
        assert(0);
    }

    int cont;
    void* aux = arrayList->objs[i];

    for(cont = i; cont < arrayList->len; cont++){
        arrayList->objs[cont] = arrayList->objs[cont+1];
    }
    (arrayList->len)--;

    return aux;
}
void* ArrayList_clear(void* self){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_clear(ArrayList(), self);

    arrayList->len=0;

    return NULL;
}
void* ArrayList_resize(void* self, int size){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);

    if(size < 0){
        printf("\nERROR: Cannot resize to %i\n", size);
        fflush(stdout);
        assert(0);
    }
    if(size == 0){
        if(arrayList->len)
            size = arrayList->len;
        else
            size = 1;
    }

    void** newObjs = malloc(sizeof(void*) * size);

    int smallestLen = size < arrayList->len ? size : arrayList->len;

    memcpy(newObjs, arrayList->objs, sizeof(void*) * smallestLen);

    free(arrayList->objs);

    arrayList->objs = newObjs;
    arrayList->len = smallestLen;
    arrayList->size = size;

    return NULL;
}
void* ArrayList_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_contains(ArrayList(), self, obj);

    bool returned = true;

    for(int i = 0; i < arrayList->len; i++){
        if(as(bool, equals(arrayList->objs[i], obj)))
            return returning(returned);
    }

    returned = false;
    return returning(returned);
}
void* ArrayList_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);
    super_indexOf(ArrayList(), self, obj);

    for(int i = 0; i < arrayList->len; i++){
        if(as(bool, equals(arrayList->objs[i], obj)))
            return returning(i);
    }

    int returned = -1;
    return returning(returned);
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
void* ArrayList_print(void* self, int bound){
    // Calling super constructor
    struct ArrayList* arrayList = cast(ArrayList(), self);

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    // Printing valid values
    for (int i = 0; i < arrayList->len; i++){
        printf("|");
        printBound(arrayList->objs[i], bound);
        printf("|\n");
        if(i < arrayList->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    // Printing empty values
    for (int i = arrayList->len; i < arrayList->size; i++){
        printf("|%*s|\n", bound, "");
        if(i < arrayList->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");

    return NULL;
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
                          _add, ArrayList_add,
                          _remove, ArrayList_remove,
                          _push, ArrayList_push,
                          _pop, ArrayList_pop,
                          _clear, ArrayList_clear,
                          _resize, ArrayList_resize,
                          _contains, ArrayList_contains,
                          _indexOf, ArrayList_indexOf,
                          _ofType, ArrayList_ofType,
                          _print, ArrayList_print,
                          NULL));
}
/* END Dynamic initializer */
