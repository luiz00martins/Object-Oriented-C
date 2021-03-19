#ifndef OOC_String_R
#define OOC_String_R

#include "../Object.r"

struct String{
    /* Object that is being extended */
    const struct Object _;

    char* text;
    int len;
    int size;
};

#endif //OOC_String_R
