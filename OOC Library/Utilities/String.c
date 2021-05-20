
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "String.h"
#include "String.r"

#define CLASS_NAME String
newClass(Object, 
    (default, ctor), 
    (default, dtor), 
    (default, print), 
    (default, printBound), 
    (default, scan), 
    (default, set), 
    (default, asArray), 
    (default, cat), 
    (default, resize), 
    (default, equals), 
    (default, lessThan), 
    (default, moreThan)
)

/* Overloaded: */
define_method(ctor){
    param(pointer, copied);

    callSuperMethod();

    // Setting up length and size
    self->len = strlen(copied);
    self->size = self->len + 1;

    // Allocating and copying string
    self->text = malloc(sizeof(char) * (self->size));
    strcpy(self->text, copied);

    returning(String, self);
}
define_method(dtor){
    callSuperMethod();

    free(self->text);

    returning(String, self);
}

/* Public: */
define_method(print){
    printf("%s", self->text);

    returning();
}

define_method(printBound){
    param(int, bound);

    if (bound < self->len) {
        for (int i = 0; i < bound - 3; i++)
            printf("%c", self->text[i]);
        printf("...");
    }
    else {
        printf("%s", self->text);
        for (int i = 0; i < bound - self->len; i++)
            printf(" ");
    }

    returning();
}

define_method(scan){
    char arr[1000];
    char c;
    scanf("%1000[^\n]%c", arr, &c);

    int copiedSize = strlen(arr) + 1;

    if (self->size < copiedSize){
        free(self->text);
        self->size = copiedSize;
        self->text = malloc(sizeof(char) * copiedSize);
    }
    self->len = copiedSize - 1;

    strcpy(self->text, arr);

    returning();
}
define_method(set){
    param(pointer, arr);

    int copiedSize = strlen(arr) + 1;

    if (self->size < copiedSize){
        free(self->text);
        self->size = copiedSize;
        self->text = malloc(sizeof(char) * copiedSize);
    }
    self->len = copiedSize - 1;

    strcpy(self->text, arr);

    // Some come here...
    returning();
}
define_method(asArray){
    return self->text;
}
define_method(cat){
    param(String, concatenated);

    // Extracting array if it's an Object
    char* arr = ((struct String*)concatenated)->text;

    int concatenatedSize = self->len + strlen(arr) + 1;

    if (self->size < concatenatedSize){
        self->size = concatenatedSize;

        char* newText = malloc(sizeof(char) * concatenatedSize);
        strcpy(newText, self->text);
        free(self->text);
        self->text = newText;
    }

    strcpy((self->text + self->len), arr);

    self->len = concatenatedSize - 1;

    returning();
}
define_method(resize){
    param(int, newLen);

    assert(newLen >= 0);

    // If newLen is 0, cut at the end of the sentence
    if (newLen == 0)
        newLen = self->len;

    // Setting up size
    self->size = newLen + 1;

    // Setting up len
    if (self->len > newLen)
        self->len = newLen;

    // Reallocating and copying text
    char* newText = malloc(sizeof(char) * self->size);
    strncpy(newText, self->text, self->len);
    free(self->text);
    self->text = newText;

    returning();
}
define_method(equals){
    param(String, str);
    
    bool returned = true;

    if(as(bool, callSuperMethod(str))){
        returning(bool, returned);
    }
    struct String* otherString = cast(String, str);

    returned = strcmp(self->text, otherString->text) == 0;
    returning(bool, returned);
}
define_method(lessThan){
    param(String, otherString);

    bool returned = false;

    if (strcmp(self->text, otherString->text) < 0) {
        returned = true;
    }

    returning(bool, returned);
}
define_method(moreThan){
    param(String, otherString);
    
    bool returned = false;

    if (strcmp(self->text, otherString->text) > 0) {
        returned = true;
    }

    returning(bool, returned);
}

