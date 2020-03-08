
#include <assert.h>
#include <stdlib.h>
#include <string.h>
#include "Char.h"
#include "Char.r"

/** START Getters and Setters **/
object_build_getset(data)
/** END Getters and Setters **/


/** START Caller functions **/
/* Public callers */

/** END Caller functions **/


/** START Class method definitions **/
void* CharClass_ctor(void* self, va_list* args){
    struct CharClass* classPtr = super_ctor(CharClass(), self, args);
    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    struct Class* selfBaseClass = classPtr;
    int argsSize = _arrayPtrSize(selfBaseClass->dataGet) - 1;
    void** tempDataGet;
    int* tempDataOffsets;
    int* tempDataSizes;

    single_addVar(Char, char, data);


    va_copy(funcArgs, *args);
    /* Overloadable function setup. All functions that go here can be overloaded*/
    while((selector = va_arg(funcArgs, voidf))){
        voidf function = va_arg(funcArgs, voidf);

        //if (selector == dataSize){
        //    classPtr->dataSize = function;
        //}
    }
    va_end(funcArgs);

    if (false /* classPtr->func == abstract */ ){

        struct Class* class = classPtr;
        class->abstract = true;
    }

    return self;
}
/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* Char_dataSize(const void* self){
    struct Char* _char = cast(Char(), self);;

    int returned = sizeof(char);
    return returning(returned);
}

void* Char_print(void* self) {
    struct Char *_char = cast(Char(), self);

    printf("%c", _char->data);

    return NULL;
}

void* Char_printBound(void* self, int bound){
    struct Char* _char = cast(Char(), self);

    if (bound < 0){
        printf("\nERROR: Object's class does not have this method\n");
        fflush(stdout);
        assert(0);
    }

    if(bound) {
        printf("%c", _char->data);
        for (int i = 0; i < bound-1; i++){
            printf(" ");
        }
    }

    return NULL;
}

void* Char_scan(void* self){
    struct Char* _char = cast(Char(), self);

    scanf("%c", &_char->data);

    return NULL;
}

void* Char_equals(void* self, void* obj){
    struct Char* _char = cast(Char(), self);

    bool returned = true;

    if(as(bool, super_equals(Char(), self, obj)))
        return returning(returned);

    struct Char* otherChar = cast(Char(), obj);

    if(_char->data == otherChar->data)
        return returning(returned);
    else{
        returned = false;
        return returning(returned);
    }
}

/* Public: */

/* Protected: */

/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _CharClass;

const void* CharClass(){
    return _CharClass ? _CharClass :
           (_CharClass = new(PrimWrapperClass(), "CharClass", PrimWrapperClass(), sizeof(struct CharClass),
                             _ctor, CharClass_ctor,
                             NULL));
}

static const void* _Char;

const void* const Char(){
    return _Char ? _Char :
           (_Char = new(CharClass(), "Char", PrimWrapper(), sizeof(struct Char),
                        _dataSize, Char_dataSize,
                        _printBound, Char_printBound,
                        _scan, Char_scan,
                        _equals, Char_equals,
                        NULL));
}
/* END Dynamic initializer */
