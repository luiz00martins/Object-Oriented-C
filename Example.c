
#include <stdio.h>
#include <assert.h>
#include "Example.h"
#include "Example.r"

/* START Function builders */
#define object_build_getter(TYPE, VAR) \
    TYPE get_##VAR(const void* self){ \
        assert(self); \
        const struct Example* example = self; \
        return example->VAR; \
    }

#define object_build_setter(TYPE, VAR) \
    void set_##VAR(void* self, TYPE v){ \
        assert(self); \
        struct Example* example = self; \
        example->VAR = v; \
    }

// Todo [Minor]: Add a new variable macro that doesn't repeat ARGS
#define object_build_caller(RET_TYPE, FUNC, TYPED_ARGS, ARGS) \
    RET_TYPE FUNC TYPED_ARGS{ \
        const struct ExampleClass* selfClass = ((const struct Object*)self)->class; \
        \
        assert(selfClass && selfClass->FUNC); \
        \
        return selfClass->FUNC ARGS; \
    }

#define object_build_super_caller(RET_TYPE, FUNC, TYPED_ARGS, ARGS) \
    RET_TYPE super_##FUNC TYPED_ARGS{ \
        const struct ExampleClass* superclass = super(class); \
        \
        assert(self && superclass); \
        \
        return superclass->FUNC ARGS; \
    }
/* END Function builders */


/* START Getters and Setters */
/* Public variable getters & setters */
object_build_getter(int, i)
object_build_getter(float, f)
object_build_getter(char, c)
object_build_setter(int, i)
object_build_setter(float, f)
object_build_setter(char, c)

/* Protected variable getters */
object_build_getter(int, pI)
object_build_getter(float, pF)
object_build_getter(char, pC)
/* END Getters and Setters */


/* START Caller functions */
/* Public callers */
object_build_caller(void, print, (const void* self), (self))
object_build_super_caller(void, print, (const struct Class* class, const void* self), (self))

object_build_caller(void, funcNoVar, (const void* self), (self))
object_build_super_caller(void, funcNoVar, (const struct Class* class, const void* self), (self))

object_build_caller(double, funcVar, (void* self, double x, double y), (self, x, y))
object_build_super_caller(double, funcVar, (const struct Class* class, void* self, double x, double y), (self, x, y))

/* Protected callers*/
object_build_caller(void, protectedFuncNoVar, (const void* self), (self))
object_build_super_caller(void, protectedFuncNoVar, (const struct Class* class, const void* self), (self))

object_build_caller(double, protectedFuncVar, (void* self, double x, double y), (self, x, y))
object_build_super_caller(double, protectedFuncVar, (const struct Class* class, void* self, double x, double y), (self, x, y))
/* END Caller functions */


/* START Class function definitions */
void* ExampleClass_ctor(void* self, va_list* args){
    struct ExampleClass* classPtr = super_ctor(ExampleClass, self, args);
    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    va_copy(funcArgs, *args);
    /* Overloadable function setup. All functions that go here can be overloaded*/
    while((selector = va_arg(*args, voidf))){
        voidf function = va_arg(*args, voidf);

        if (selector == funcNoVar){
            classPtr->funcNoVar = function;
        }
        else if (selector == funcVar) {
            classPtr->funcVar = function;
        }
        else if (selector == print) {
            classPtr->print = function;
        }
        else if (selector == protectedFuncNoVar) {
            classPtr->protectedFuncNoVar = function;
        }
        else if (selector == protectedFuncVar) {
            classPtr->protectedFuncVar = function;
        }
    }
    va_end(funcArgs);

    return self;
}
/* END Class function definitions */


/* START Object function definitions */
/* Public functions */
void* Example_ctor(void* self, va_list* args){
    assert(self);

    struct Example* example = super_ctor(Example, self, args);

    // Note: The conversions are happening because of the implicit compiler promotions
    example->i = va_arg(*args, int);
    example->f = (float)va_arg(*args, double);
    example->c = (char)va_arg(*args, int);
    example->pI = va_arg(*args, int);
    example->pF = (float)va_arg(*args, double);
    example->pC = (char)va_arg(*args, int);

    return self;
}
void Example_print(const void* self){
    assert(self);

    struct Example* example = self;

    printf("%i %f %c %i %f %c ", example->i, example->f, example->c, example->pI, example->pF, example->pC);
}
void Example_funcNoVar(const void* self){
    assert(self);

    struct Example* example = self;

    // Some come here...
}
double Example_funcVar(void* self, double x, double y){
    assert(self);

    struct Example* example = self;

    // Some come here...
    return 0.0;
}

/* Protected functions */
void Example_protectedFuncNoVar(const void* self){
    assert(self);

    struct Example* example = self;

    // Some come here...
}
double Example_protectedFuncVar(void* self, double x, double y){
    assert(self);

    struct Example* example = self;

    // Some come here...

}
/* END Object function definitions */

/* START Initializer */
void initExample(){
    if(!ExampleClass){
        ExampleClass = new(Class, "ExampleClass", Class, sizeof(struct ExampleClass),
                         ctor, ExampleClass_ctor,
                         0);
    }
    if(!Example){
        Example = new(ExampleClass, "Example", Object, sizeof(struct Example),
                    ctor, Example_ctor,
                    print, Example_print,
                    funcNoVar, Example_funcNoVar,
                    funcVar, Example_funcVar,
                    protectedFuncNoVar, Example_protectedFuncNoVar,
                    protectedFuncVar, Example_protectedFuncVar,
                    NULL);
    }
}
/* END Initializer */