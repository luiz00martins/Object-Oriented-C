
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "String.h"
#include "String.r"


/** START Getters and Setters **/
object_build_getset(text, len, size)
/** END Getters and Setters **/

build_caller_funcs(print, asArray, cat, resize)

/** START Caller functions **/
build_funcs(String,
        (ctor, (va_list*, nargs)),
        (dtor, ()),
        (print, ()),
        (printBound, (int, bound)),
        (scan, ()),
        (set, (void*, copied)),
        (asArray, ()),
        (cat, (void*, concatenated)),
        (resize, (int, size)),
        (equals, (void*, string)))


/** END Caller functions **/

/** START Class method definitions **/
build_class_ctor(String,
        ((char*, text), (int, len), (int, size)),
        (       (print, ()),
                (printBound, (int, bound)),
                (scan, ()),
                (set, (void*, copied)),
                (asArray, ()),
                (cat, (void*, concatenated)),
                (resize, (int, size))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* String_ctor(void* self, va_list* args){
    cast(String(), self);
    // Calling super constructor
    struct String* string = super_ctor(String(), self, args);

    // Note: The conversions are happening because of the implicit compiler promotions
    void* copied = va_arg(*args, void*);

    // Extracting array if it's an Object
    char* arr;
    if(isAnObject(copied))
        arr = ((struct String*)copied)->text;
    else
        arr = copied;

    // Setting up length and size
    string->len = strlen(arr);
    string->size = string->len + 1;

    // Allocating and copying string
    string->text = malloc(sizeof(char) * (string->size));
    strcpy(string->text, arr);

    return self;
}
void* String_dtor(void* self){
    cast(String(), self);
    // Calling super destructor
    struct String* string = super_dtor(String(), self);

    free(string->text);

    return self;
}

/* Public: */
void* String_print(void* self){
    struct String* string = cast(String(), self);

    printf("%s", string->text);

    return NULL;
}

void* String_printBound(void* self, int bound){
    struct String* string = cast(String(), self);

    if (bound < string->len) {
        for (int i = 0; i < bound - 3; i++)
            printf("%c", string->text[i]);
        printf("...");
    }
    else {
        printf("%s", string->text);
        for (int i = 0; i < bound - string->len; i++)
            printf(" ");
    }

    return NULL;
}

void* String_scan(void* self){
    struct String* string = cast(String(), self);

    char arr[1000];
    char c;
    scanf("%1000[^\n]%c", arr, &c);

    int copiedSize = strlen(arr) + 1;

    if (string->size < copiedSize){
        free(string->text);
        string->size = copiedSize;
        string->text = malloc(sizeof(char) * copiedSize);
    }
    string->len = copiedSize - 1;

    strcpy(string->text, arr);

    return NULL;
}
void* String_set(void* self, void* copied){
    struct String* string = cast(String(), self);

    // Extracting array if it's an Object
    char* arr;
    if(isAnObject(copied))
        arr = ((struct String*)copied)->text;
    else
        arr = copied;

    int copiedSize = strlen(arr) + 1;

    if (string->size < copiedSize){
        free(string->text);
        string->size = copiedSize;
        string->text = malloc(sizeof(char) * copiedSize);
    }
    string->len = copiedSize - 1;

    strcpy(string->text, arr);

    // Some come here...
    return NULL;
}
void* String_asArray(void* self){
    struct String* string = cast(String(), self);

    return string->text;
}
void* String_cat(void* self, void* concatenated){
    struct String* string = cast(String(), self);

    // Extracting array if it's an Object
    char* arr;
    if(isAnObject(concatenated))
        arr = ((struct String*)concatenated)->text;
    else
        arr = concatenated;

    int concatenatedSize = string->len + strlen(arr) + 1;

    if (string->size < concatenatedSize){
        string->size = concatenatedSize;

        char* newText = malloc(sizeof(char) * concatenatedSize);
        strcpy(newText, string->text);
        free(string->text);
        string->text = newText;
    }

    strcpy((string->text + string->len), arr);

    string->len = concatenatedSize - 1;

    return NULL;
}
void* String_resize(void* self, int newLen){
    assert(newLen >= 0);

    struct String* string = cast(String(), self);

    // If newLen is 0, cut at the end of the sentence
    if (newLen == 0)
        newLen = string->len;

    // Setting up size
    string->size = newLen + 1;

    // Setting up len
    if (string->len > newLen)
        string->len = newLen;

    // Reallocating and copying text
    char* newText = malloc(sizeof(char) * string->size);
    strncpy(newText, string->text, string->len);
    free(string->text);
    string->text = newText;

    return NULL;
}
void* String_equals(void* self, void* str){
    struct String* string = cast(String(), self);
    bool returned = true;

    if(as(bool, super_equals(String(), self, str)))
        return returning(returned);

    struct String* otherString = cast(String(), str);

    returned = strcmp(string->text, otherString->text) == 0;
    return returning(returned);
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _StringClass;

const void* const StringClass(){
    return _StringClass ? _StringClass :
           (_StringClass = new(Class(), "StringClass", Class(), sizeof(struct StringClass),
                                _ctor, StringClass_ctor,
                                NULL));
}

static const void* _String;

const void* const String(){
    return _String ? _String :
           (_String = new(StringClass(), "String", Object(), sizeof(struct String),
                           _ctor, String_ctor,
                           _dtor, String_dtor,
                           _print, String_print,
                           _printBound, String_printBound,
                           _scan, String_scan,
                           _set, String_set,
                           _asArray, String_asArray,
                           _cat, String_cat,
                           _resize, String_resize,
                           _equals, String_equals,
                           NULL));
}
/* END Dynamic initializer */
