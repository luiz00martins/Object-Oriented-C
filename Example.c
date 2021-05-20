
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Example.r"

#define CLASS_NAME Example
newClass(Object,
    (default, ctor),
    (default, dtor),
    (default, print),
    (default, funcNoVar),
    (default, funcVar),
    (default, protectedFuncNoVar),
    (default, protectedFuncVar)
)

/* Overloaded: */
define_method(ctor){
    param(int, i);
    param(float, f);
    param(char, c);
    param(int, protI);
    param(float, protF);
    param(char, protC);
    
    self->i = i;
    self->f = f;
    self->c = c;
    self->protI = protI;
    self->protF = protF;
    self->protC = protC;
    self->ptrC = malloc(sizeof(char) * 50);

    printf("I'm alive.\n");

    return self;
}
define_method(dtor){
    free(self->ptrC);
    printf("I'm dead.\n");

    return self;
}

/* Public: */
define_method(print){
    printf("%i %f %c %i %f %c ", self->i, self->f, self->c, self->protI, self->protF, self->protC);
    return NULL;
}
define_method(funcNoVar){
    // Some come here...
    return NULL;
}
define_method(funcVar){
    param(double, x);
    param(double, y);

    self->i = x;
    self->f = y;

    // Some come here...
    return NULL;
}

/* Protected: */
define_method(protectedFuncNoVar){

    // Some come here...
    return NULL;
}
define_method(protectedFuncVar){
    param(double, x);
    param(double, y);
    param(Object, protC);
    // Some come here...
    
    returning();
}

