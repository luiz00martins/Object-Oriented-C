#ifndef OOC_EXAMPLE_H
#define OOC_EXAMPLE_H

#include "Object.h"


/* Public variable getters & setters */
int get_i(const void* self);
float get_f(const void* self);
char get_c(const void* self);
void set_i(void* self, int i);
void set_f(void* self, float f);
void set_c(void* self, char c);

/* Protected variable getters */
int get_pI(const void* self);
float get_pF(const void* self);
char get_pC(const void* self);

/* Public function callers */
void print(const void* self);
void funcNoVar(const void* self);
double funcVar(void* self, double x, double y);


/* Initializer */
void initExample();


/* Object builder */
const struct ExampleClass* Example;

#endif //OOC_EXAMPLE_H
