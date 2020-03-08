
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "ArrayStack.h"
#include "ArrayStack.r"
#include "../Wrappers/PrimWrapper.h"


/** START Getters and Setters **/
build_decl_get(objs);
build_decl_get(type);
build_decl_get(len);
build_decl_get(size);
/** END Getters and Setters **/

/** START Caller functions **/
build_funcs(ArrayStack,
            (ctor, (va_list*, nargs)),
            (dtor, ()),
            (peek, ()),
            (push, (void*, obj)),
            (pop, ()),
            (clear, ()),
            (resize, (int, size)),
            (contains, (void*, obj)),
            (indexOf, (void*, obj)),
            (ofType, (void*, class)),
            (print, (int, bound)))
/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(ArrayStack,
        ((void**, objs), (int, len), (int, size), (struct Class*, type)),
        ((resize, (int, size)),
         (print, (int, bound))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* ArrayStack_ctor(void* self, va_list* args){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_ctor(ArrayStack(), self, args);

    // Gathering arguments
    arrayStack->type = va_arg(*args, void*);

    arrayStack->objs = malloc(sizeof(void*));
    arrayStack->len = 0;
    arrayStack->size = 1;

    return self;
}
void* ArrayStack_dtor(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_dtor(ArrayStack(), self);

    free(arrayStack->objs);

    return self;
}
void* ArrayStack_peek(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_peek(ArrayStack(), self);

    if(arrayStack->len > 0)
        return arrayStack->objs[arrayStack->len - 1];
    else
        return NULL;
}
void* ArrayStack_push(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_push(ArrayStack(), self, obj);

    if(arrayStack->size == arrayStack->len){
        resize(arrayStack, arrayStack->size * 2);
    }

    arrayStack->objs[arrayStack->len] = obj;
    arrayStack->len++;

    return NULL;
}
void* ArrayStack_pop(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_pop(ArrayStack(), self);

    if(arrayStack->len == 0){
        printf("\nERROR: Cannot pop item from empty stack\n");
        fflush(stdout);
        assert(0);
    }

    arrayStack->len--;

    return arrayStack->objs[arrayStack->len];
}
void* ArrayStack_clear(void* self){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_clear(ArrayStack(), self);

    arrayStack->len = 0;

    return NULL;
}
void* ArrayStack_resize(void* self, int size){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);

    if(size < 0){
        printf("\nERROR: Cannot resize to %i\n", size);
        fflush(stdout);
        assert(0);
    }
    if(size == 0){
        if(arrayStack->len)
            size = arrayStack->len;
        else
            size = 1;
    }

    void** newObjs = malloc(sizeof(void*) * size);

    int smallestLen = size < arrayStack->len ? size : arrayStack->len;

    memcpy(newObjs, arrayStack->objs, sizeof(void*) * smallestLen);

    free(arrayStack->objs);

    arrayStack->objs = newObjs;
    arrayStack->len = smallestLen;
    arrayStack->size = size;

    return NULL;
}
void* ArrayStack_contains(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_contains(ArrayStack(), self, obj);

    bool returned = true;

    for(int i = 0; i < arrayStack->len; i++){
        if(equals(arrayStack->objs[i], obj))
            return returning(returned);
    }

    returned = false;
    return returning(returned);
}
void* ArrayStack_indexOf(void* self, void* obj){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_indexOf(ArrayStack(), self, obj);

    for(int i = 0; i < arrayStack->len; i++){
        if(as(bool, equals(arrayStack->objs[i], obj)))
            return returning(i);
    }

    int returned = -1;
    return returning(returned);
}
void* ArrayStack_ofType(void* self, void* class){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);
    super_ofType(ArrayStack(), self, class);

    // Verifyting if it's really a class
    cast(Class(), class);

    bool returned;
    if(arrayStack->type == class){
        returned = true;
        return returning(returned);
    }
    else {
        returned = false;
        return returning(returned);
    }
}
void* ArrayStack_print(void* self, int bound){
    // Calling super constructor
    struct ArrayStack* arrayStack = cast(ArrayStack(), self);

    for(int i = 0; i < bound+2; i++)
        printf("=");
    printf("\n");
    // Printing valid values
    for (int i = 0; i < arrayStack->len; i++){
        printf("|");
        printBound(arrayStack->objs[i], bound);
        printf("|\n");
        if(i < arrayStack->size-1){
            printf("|");
            for(int j = 0; j < bound; j++)
                printf("-");
            printf("|\n");
        }
    }
    // Printing empty values
    for (int i = arrayStack->len; i < arrayStack->size; i++){
        printf("|%*s|\n", bound, "");
        if(i < arrayStack->size-1){
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
static const void* _ArrayStackClass;

const void* const ArrayStackClass(){
    return _ArrayStackClass ? _ArrayStackClass :
           (_ArrayStackClass = new(StackClass(), "ArrayStackClass", StackClass(), sizeof(struct ArrayStackClass),
                               _ctor, ArrayStackClass_ctor,
                               NULL));
}

static const void* _ArrayStack;

const void* const ArrayStack(){
    return _ArrayStack ? _ArrayStack :
           (_ArrayStack = new(ArrayStackClass(), "ArrayStack", Stack(), sizeof(struct ArrayStack),
                          _ctor, ArrayStack_ctor,
                          _dtor, ArrayStack_dtor,
                          _peek, ArrayStack_peek,
                          _push, ArrayStack_push,
                          _pop, ArrayStack_pop,
                          _clear, ArrayStack_clear,
                          _resize, ArrayStack_resize,
                          _contains, ArrayStack_contains,
                          _indexOf, ArrayStack_indexOf,
                          _ofType, ArrayStack_ofType,
                          _print, ArrayStack_print,
                          NULL));
}
/* END Dynamic initializer */
