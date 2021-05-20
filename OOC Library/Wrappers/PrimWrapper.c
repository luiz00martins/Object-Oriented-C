#include <assert.h>
#include <string.h>
#include "PrimWrapper.h"
#include "PrimWrapper.r"

#define CLASS_NAME PrimWrapper
newClass(Wrapper,
    (abstract, ctor),
    (abstract, get),
    (abstract, dataSize),
    (abstract, print),
    (abstract, printBound)
)











