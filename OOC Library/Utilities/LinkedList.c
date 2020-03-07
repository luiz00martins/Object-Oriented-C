
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "LinkedList.h"
#include "LinkedList.r"


/** START Getters and Setters **/
object_build_getset(head)
build_decl_get(len);
build_decl_get(type);
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
            (contains, (void*, obj)),
            (ofType, (void*, class)),
            (print, (int, bound)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(LinkedList,
                 ((LinkedNode*, head), (int, len), (struct Class*, type)),
                 ())

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* LinkedList_ctor(void* self, va_list* args){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_ctor(LinkedList(), self, args);

    // Gathering arguments
    linkedList->type = va_arg(*args, void*);



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
void* LinkedList_ofType(void* self, void* class){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);
    super_ofType(LinkedList(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(linkedList->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
void* LinkedList_print(void* self, int bound){
    // Calling super constructor
    struct LinkedList* linkedList = cast(LinkedList(), self);

    /*
    // Figuring out which one should be printed
    bool* printed = malloc(sizeof(bool) * arrayQueue->size);
    for (int i = 0; i < arrayQueue->size; i++)
        printed[i] = false;

    if (arrayQueue->start < arrayQueue->end){
        for(int i = 0; i < arrayQueue->size; i++){
            if(i >= arrayQueue->start && i <= arrayQueue->end)
                printed[i] = true;
        }
    }
    else if (arrayQueue->end < arrayQueue->start){
        for(int i = 0; i < arrayQueue->size; i++){
            if(i >= arrayQueue->start || i <= arrayQueue->end)
                printed[i] = true;
        }
    }
    else if (arrayQueue->len == 1){
        printed[arrayQueue->start] = true;
    }


    //Printing
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    for (int i = 0; i < arrayQueue->size; i++){
        if(printed[i])
            print(arrayQueue->objs[i], bound);
        else {
            printf("|%*s|\n", bound, "");
        }
        if(i < arrayQueue->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");


    free(printed);
    */

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
                             _contains, LinkedList_contains,
                             _indexOf, LinkedList_indexOf,
                             _ofType, LinkedList_ofType,
                             _print, LinkedList_print,
                             NULL));
}
/* END Dynamic initializer */
