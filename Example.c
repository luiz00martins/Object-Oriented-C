
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include "Example.h"
#include "Example.r"


/** START Getters and Setters **/
object_build_getset(i, f, c, ptrC, protI, protF, protC, privI, privF, privC)
/** END Getters and Setters **/

build_caller_funcs(print, funcNoVar, funcVar, protectedFuncNoVar, protectedFuncVar)

/** START Caller functions **/
build_funcs(Example,
          (ctor, (va_list*, nargs)),
          (dtor, ()),
          (print, ()),
          (funcNoVar, ()),
          (funcVar, (double, x, double, y)),
          (protectedFuncNoVar, ()),
          (protectedFuncVar, (double, x, double, y)))


/** END Caller functions **/


/** START Class method definitions **/
build_class_ctor(Example,
                 ((int, i), (float, f), (char, c), (char*, ptrC), (int, protI), (float, protF), (char, protC), (int, privI), (float, privF), (char, privC)),
                 (  (print, ()),
                    (funcNoVar, ()),
                    (funcVar, (double, x, double, y)),
                    (protectedFuncNoVar, ()),
                    (protectedFuncVar, (double, x, double, y))))

/** END Class method definitions **/


/** START Object method definitions **USER CODE** **/
/* Overloaded: */
void* Example_ctor(void* self, va_list* args){
    cast(Example(), self);
    // Calling super constructor
    struct Example* example = super_ctor(Example(), self, args);

    // Note: The conversions are happening because of the implicit compiler promotions
    example->i = (int)va_arg(*args, int);
    example->f = (float)va_arg(*args, double);
    example->c = (char)va_arg(*args, int);
    example->protI = (int)va_arg(*args, int);
    example->protF = (float)va_arg(*args, double);
    example->protC = (char)va_arg(*args, int);
    example->ptrC = malloc(sizeof(char) * 50);

    return self;
}
void* Example_dtor(void* self){
    cast(Example(), self);
    // Calling super destructor
    struct Example* example = super_dtor(Example(), self);

    free(example->ptrC);

    return self;
}

/* Public: */
void* Example_print(void* self){
    struct Example* example = cast(Example(), self);

    printf("%i %f %c %i %f %c ", example->i, example->f, example->c, example->protI, example->protF, example->protC);
    return NULL;
}
void* Example_funcNoVar(void* self){
    struct Example* example = cast(Example(), self);

    // Some come here...
    return NULL;
}
void* Example_funcVar(void* self, double x, double y){
    struct Example* example = cast(Example(), self);

    example->i = x;
    example->f = y;

    // Some come here...
    return NULL;
}

/* Protected: */
void* Example_protectedFuncNoVar(void* self){
    struct Example* example = cast(Example(), self);

    // Some come here...
    return NULL;
}
void* Example_protectedFuncVar(void* self, double x, double y){
    struct Example* example = cast(Example(), self);

    // Some come here...
    return NULL;
}
/** END Object method definitions **USER CODE** **/

/* START Dynamic initializer */
static const void* _ExampleClass;

const void* ExampleClass(){
    return _ExampleClass ? _ExampleClass :
           (_ExampleClass = new(Class(), "ExampleClass", Class(), sizeof(struct ExampleClass),
                                _ctor, ExampleClass_ctor,
                                NULL));
}

static const void* _Example;

//TODO: Add impossibility of overload

const void* const Example(){
    return _Example ? _Example :
           (_Example = new(ExampleClass(), "Example", Object(), sizeof(struct Example),
                           _ctor, Example_ctor,
                           _dtor, Example_dtor,
                           _print, Example_print,
                           _funcNoVar, Example_funcNoVar,
                           _funcVar, Example_funcVar,
                           _protectedFuncNoVar, Example_protectedFuncNoVar,
                           _protectedFuncVar, Example_protectedFuncVar,
                           NULL));
}
/* END Dynamic initializer */
