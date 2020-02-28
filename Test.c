
#define TRUE 1
#define FALSE 0

//---String definitions-START
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <assert.h>
#include "OOCLib.h"
#include "Example.h"

/*
typedef struct {
    char *text;
    int len;
} string;

//Allocates and sets up the "str" string with the set length
void strinit(string *str, int length) {
    int i;

    str->text = (char*) malloc(length * sizeof(char)); //Allocating memory for the string
    str->len = length; //Setting the length

    //Setting all characters to null
    for (i = 0; i < str->len; i++) {
        str->text[i] = '\0';
    }

    return;
}

//Deallocates the string
void strend(string* str) {
    free(str->text);
    str->len = 0;
}

//Clears all valid characters from "str"
void strclear(string* str) {
    int i;

    //Setting all the valid characters to null
    for (i = 0; str->text[i] != '\0'; i++) {
        str->text[i] = '\0';
    }
    return;
}

//Copies the text from the original to the copy
void strcopy(string* copy, string *original) {
    int i;

    strclear(copy);

    //Copies all characters, leaving only the last '\0'
    for (i = 0; i < (copy->len- 1) && original->text[i] != '\0'; i++) {
        copy->text[i] = original->text[i];
    }
    return;
}

//Copies the text from the original to the copy
void strset(string* copy, const char* original) {
    int i;
    strclear(copy);

    //Copies all the characters, leaving only the last '\0'
    for (i = 0; i < (copy->len - 1) && original[i] != '\0'; i++){
        copy->text[i] = original[i];
    }
    return;
}

//Concatenates the "cat" string at the end of "str"
void strcat(string* str, string* cat) {
    int i, j;
    //Finds the end of "str"
    for (i = 0; str->text[i] != '\0'; i++);

    //Copies all the characters to the end of "str", leaving only the last '\0'
    for (j = 0; i < (str->len - 1) && cat->text[j] != '\0'; i++ ,j++){
        str->text[i] = cat->text[j];
    }
    return;
}

//Concatenates the "c" char at the end of "str"
void strcatc(string* str, char c) {
    int i, j;
    //Finds the end of "str"
    for (i = 0; str->text[i] != '\0'; i++);

    //Copies all the characters to the end of "str", leaving only the last '\0'
    if (i < (str->len - 1)){
        str->text[i] = c;
    }
    return;
}

//Resizes the string with set length
void strres(string *str, int length) {
    string dummy;
    strinit(&dummy, str->len);

    strcopy(&dummy, str);

    strend(str);
    strinit(str, length);

    strcopy(str, &dummy);

    strend(&dummy);
    return;
}

//Returns the length of the valid string
int strlen(string* str){
    int i;
    for (i = 0; str->text[i] != '\0'; i++);
    return i;
}

//Reads from user input until a '\n' is found
void strin(string* str) {
    int i;
    char ctemp = '\0';

    strclear(str);
    //Copies all the characters, leaving only the last '\0' or an '\n' is found
    for (i = 0; i < (str->len - 1) && ctemp != '\n'; i++){
        scanf("%c", &ctemp);
        str->text[i] = ctemp;
    }
    //Deletes the '\n' at the end, if it exists
    if (str->text[i - 1] == '\n'){
        str->text[i - 1] = '\0';
    }
    //If the "else" loop is activated, the "for" loop didn't consume all typed characters, so , to avoid buffer overflow, it will consume the rest of teh characters
    else {
        for (i = 0; ctemp != '\n'; i++){
            scanf("%c", &ctemp);
        }
    }

    return;
}

//Reads from user input until the "c" character is found
//- if "c" character is not found, the function will read until a '\n'
//- '\0' can't be used in "c"
void strinc(string* str, char c) {
    if (c == '\0') return;

    int i;
    char ctemp = '\0';

    strclear(str);
    //Copies all the characters, leaving only the last '\0', or an "c" or '\n'  is found
    for (i = 0; i < (str->len - 1) && (ctemp != c && ctemp != '\n'); i++){
        scanf("%c", &ctemp);
        str->text[i] = ctemp;
    }

    //Deletes the "c" at the end, if it exists
    if (str->text[i - 1] == c || str->text[i - 1] == '\n'){
        str->text[i - 1] = '\0';
    }
    else {
        //If the "else" loop is activated, the "for" loop didn't consume all typed characters, so, to avoid buffer overflow, it will consume the rest of teh characters
        for (i = 0; ctemp != c; i++){
            scanf("%c", &ctemp);
        }
    }

    return;
}

//Compares all the characters from "str0" to "str1"
//If they all match, returns 1, otherwise, returns 0
int strcomp(string* str0, string* str1){
    if (strlen(str0) != strlen(str1)){
        return 0;
    }
    else {
        int i;
        int len = strlen(str0);
        for (i = 0; i < len; i++){
            if(str0->text[i] != str1->text[i]){
                return 0;
            }
        }
        return 1;
    }
}
//---String definitions-END
*/

#define interpretAs(TYPE, FUNC) (*((TYPE*)FUNC))


int main() {
    void* ptr = new(Example(), 10, 10.0, 'a', 20, 20.0, 'b');
    print(ptr);
    printf("\n");

    float x = 101;
    double y = 202;

    funcVar(ptr, x, y);

    print(ptr);

    delete(ptr);

    return 0;
}
