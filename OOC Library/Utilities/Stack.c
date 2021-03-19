
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Stack.h"
#include "Stack.r"


#define CLASS_NAME Stack
newClass(Object, 
    (abstract, peek),
    (abstract, push),
    (abstract, pop),
    (abstract, clear),
    (abstract, contains),
    (abstract, indexOf),
    (abstract, ofType)
)

