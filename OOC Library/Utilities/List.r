#ifndef OOC_List_R
#define OOC_List_R

#include "../Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct List{
    /* Object that is being extended */
    const struct Object _;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ListClass{
    /* Class that is being extended */
    const struct Object _;

    void* (*_get)();
    void* (*caller_get)();
    void* (*this_get)(void* self, int i);

    void* (*_add)();
    void* (*caller_add)();
    void* (*this_add)(void* self, int i, void* obj);

    void* (*_remove)();
    void* (*caller_remove)();
    void* (*this_remove)(void* self, int i);

    void* (*_push)();
    void* (*caller_push)();
    void* (*this_push)(void* self, void* obj);

    void* (*_pop)();
    void* (*caller_pop)();
    void* (*this_pop)(void* self, int i);

    void* (*_clear)();
    void* (*caller_clear)();
    void* (*this_clear)(void* self);

    void* (*_contains)();
    void* (*caller_contains)();
    void* (*this_contains)(void* self, void* obj);

    void* (*_indexOf)();
    void* (*caller_indexOf)();
    void* (*this_indexOf)(void* self, void* obj);

    void* (*_ofType)();
    void* (*caller_ofType)();
    void* (*this_ofType)(void* self, void* class);
};

/* super callers */
void* _super_get(struct Object* class, void* self, ...);
#define super_get(class, self, ...) _super_get(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_add(struct Object* class, void* self, ...);
#define super_add(class, self, ...) _super_add(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_remove(struct Object* class, void* self, ...);
#define super_remove(class, self, ...) _super_remove(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_push(struct Object* class, void* self, ...);
#define super_push(class, self, ...) _super_push(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_pop(struct Object* class, void* self, ...);
#define super_pop(class, self, ...) _super_pop(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_clear(struct Object* class, void* self, ...);
#define super_clear(class, self, ...) _super_clear(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_contains(struct Object* class, void* self, ...);
#define super_contains(class, self, ...) _super_contains(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_indexOf(struct Object* class, void* self, ...);
#define super_indexOf(class, self, ...) _super_indexOf(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_ofType(struct Object* class, void* self, ...);
#define super_ofType(class, self, ...) _super_ofType(class, self, ##__VA_ARGS__, FUNC_END)

/** END Method management **/


/* Class builder */
const void* const ListClass();

#endif //OOC_List_R
