#include <assert.h>
#include <string.h>
#include "Wrapper.h"
#include "Wrapper.r"

#define CLASS_NAME Wrapper
newClass(Object,
    (abstract, ctor),
    (abstract, dataSize),
    (abstract, get)
)


