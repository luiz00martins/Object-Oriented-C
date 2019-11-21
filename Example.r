#ifndef EXAMPLE_R
#define EXAMPLE_R

#include "Object.r"

/* Object constructor structure */
struct Example{
    /* Object that is being extended */
    const struct Object _;

    /* Public variables */
    int i;
    float f;
    char c;
    /* Protected variables */
    int pI;
    float pF;
    char pC;
};


/* Variable accessers */
#define super_i(point) (((const struct Point*)(point))->i)
#define super_f(point) (((const struct Point*)(point))->f)
#define super_c(point) (((const struct Point*)(point))->c)
#define super_pI(point) (((const struct Point*)(point))->pI)
#define super_pF(point) (((const struct Point*)(point))->pF)
#define super_pC(point) (((const struct Point*)(point))->pC)


/* Class constructor structure */
struct ExampleClass{
    /* Class that is being extended */
    const struct Class _;

    /* Public functions */
    void (*print)(const void*);
    void (*funcNoVar)(const void*);
    double (*funcVar)(void*, double, double);

    /* Protected functions */
    void (*protectedFuncNoVar)(const void*);
    double (*protectedFuncVar)(void*, double, double);
};

/* Public super callers */
void super_print(const struct Class* class, const void* self);
void super_funcNoVar(const struct Class* class, const void* self);
double super_funcVar(const struct Class* class, void* self, double x, double y);

/* Protected function callers */
void protectedFuncNoVar(const void* self);
double protectedFuncVar(void* self, double x, double y);
/* Protected super callers */
void super_protectedFuncNoVar(const struct Class* class, const void* self);
double super_protectedFuncVar(const struct Class* class, void* self, double x, double y);


/* Class constructor */
const struct Class* ExampleClass;

#endif //EXAMPLE_R