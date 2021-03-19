#ifndef OOC_EXAMPLE_R
#define OOC_EXAMPLE_R

#include "OOC Library/Object.r"
#include "Example.h"

/** START Variable manegement **/
/* Object constructor structure */
struct Example{
    /* Object that is being extended */
    const struct Object _;

    /* Public: */
    int i;
    float f;
    char c;
    /* Public variable that uses constructor and destructor */
    char* ptrC;
    /* Protected: */
    int protI;
    float protF;
    char protC;
    /* Private: */
    int privI;
    float privF;
    char privC;
};

// Protected method definitions
#define protectedFuncNoVar(self, ...) callMethod("protectedFuncNoVar", self, __VA_ARGS__)
#define protectedFuncVar(self, ...) callMethod("protectedFuncVar", self, __VA_ARGS__)

#endif //OOC_EXAMPLE_R
