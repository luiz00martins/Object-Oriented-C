
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Queue.h"
#include "Queue.r"

#define CLASS_NAME Queue
newClass(Object,
    (abstract, peek),
    (abstract, push),
    (abstract, pop),
    (abstract, clear),
    (abstract, contains),
    (abstract, indexOf),
    (abstract, ofType)
)
