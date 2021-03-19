
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "List.h"
#include "List.r"


#define CLASS_NAME List
newClass(Object,
    (abstract, get),
    (abstract, add),
    (abstract, remove),
    (abstract, push),
    (abstract, pop),
    (abstract, clear),
    (abstract, contains),
    (abstract, indexOf),
    (abstract, ofType)
)