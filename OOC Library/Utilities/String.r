#ifndef OOC_String_R
#define OOC_String_R

#include "../Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct String{
    /* Object that is being extended */
    const struct Object _;

    char* text;
    int len;
    int size;
};

/* Public and Protected variable accessers */
#define super_text(obj) (((const struct String*)(obj))->text)
#define super_len(obj) (((const struct String*)(obj))->len)
#define super_size(obj) (((const struct String*)(obj))->size)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct StringClass{
    /* Class that is being extended */
    const struct Class _;

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self);

    void* (*_set)();
    void* (*caller_set)();
    void* (*this_set)(void* self, void* copied);

    void* (*_asArray)();
    void* (*caller_asArray)();
    void* (*this_asArray)(void* self);

    void* (*_cat)();
    void* (*caller_cat)();
    void* (*this_cat)(void* self, void* concatenated);

    void* (*_resize)();
    void* (*caller_resize)();
    void* (*this_resize)(void* self, int size);

    void* (*_compare)();
    void* (*caller_compare)();
    void* (*this_compare)(void* self, void* string);
};

/* super callers */
void* _super_print(struct Class* class, void* self, ...);
#define super_print(class, self, ...) _super_print(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_set(struct Class* class, void* self, ...);
#define super_set(class, self, ...) _super_set(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_asArray(struct Class* class, void* self, ...);
#define super_asArray(class, self, ...) _super_asArray(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_cat(struct Class* class, void* self, ...);
#define super_cat(class, self, ...) _super_cat(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_resize(struct Class* class, void* self, ...);
#define super_resize(class, self, ...) _super_resize(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_compare(struct Class* class, void* self, ...);
#define super_compare(class, self, ...) _super_compare(class, self, ##__VA_ARGS__, FUNC_END)

/** END Method management **/


/* Class builder */
const void* const StringClass();

#endif //OOC_String_R
