#ifndef OOC_EXAMPLE_R
#define OOC_EXAMPLE_R

#include "OOC Library/Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Example{
    /* Object that is being extended */
    const struct Object _;

    /* Public: */
    int i;
    float f;
    char c;
    /* Public variable that uses constructor and destructor */
    char* ptrC;
    /* Protected: */
    int protI;
    float protF;
    char protC;
    /* Private: */
    int privI;
    float privF;
    char privC;
};

/* Public and Protected variable accessers */
#define super_i(obj) (((const struct Example*)(obj))->i)
#define super_f(obj) (((const struct Example*)(obj))->f)
#define super_c(obj) (((const struct Example*)(obj))->c)
#define super_ptrC(obj) (((const struct Example*)(obj))->ptrC)
#define super_protI(obj) (((const struct Example*)(obj))->protI)
#define super_protF(obj) (((const struct Example*)(obj))->protF)
#define super_protC(obj) (((const struct Example*)(obj))->protC)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ExampleClass{
    /* Class that is being extended */
    const struct Class _;

    /* Public: */
    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self);

    void* (*_funcNoVar)();
    void* (*caller_funcNoVar)();
    void* (*this_funcNoVar)(void* self);

    void* (*_funcVar)();
    void* (*caller_funcVar)();
    void* (*this_funcVar)(void* self, double x, double y);

    /* Protected: */
    void* (*_protectedFuncNoVar)();
    void* (*caller_protectedFuncNoVar)();
    void* (*this_protectedFuncNoVar)(void* self);

    void* (*_protectedFuncVar)();
    void* (*caller_protectedFuncVar)();
    void* (*this_protectedFuncVar)(void* self, double x, double y);
};

/* Super callers */
void* _super_print(struct Class* class, void* self, ...);
#define super_print(class, self, ...) _super_print(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_funcNoVar(struct Class* class, void* self, ...);
#define super_funcNoVar(class, self, ...) _super_funcNoVar(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_funcVar(struct Class* class, void* self, ...);
#define super_funcVar(class, self, ...) _super_funcVar(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_protectedFuncNoVar(struct Class* class, void* self, ...);
#define super_protectedFuncNoVar(class, self, ...) _super_protectedFuncNoVar(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_protectedFuncVar(struct Class* class, void* self, ...);
#define super_protectedFuncVar(class, self, ...) _super_protectedFuncVar(class, self, ##__VA_ARGS__, FUNC_END)

/* Protected function callers */
void* _protectedFuncNoVar(void* self, ...);
#define protectedFuncNoVar(self, ...) _protectedFuncNoVar(self, ##__VA_ARGS__, FUNC_END)
void* _protectedFuncVar(void* self, ...);
#define protectedFuncVar(self, ...) _protectedFuncVar(self, ##__VA_ARGS__, FUNC_END)
/* Protected super callers */
/** END Method management **/


/* Class builder */
const void* const ExampleClass();

#endif //OOC_EXAMPLE_R
