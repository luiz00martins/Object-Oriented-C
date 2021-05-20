#ifndef OOC_ArrayStack_R
#define OOC_ArrayStack_R

#include "Stack.r"

/** START Variable manegement **/
/* Object constructor structure */
struct ArrayStack{
    /* Object that is being extended */
    const struct Stack _;

    struct Object** objs;
    int len;
    int size;
    class type;
};

/* Public and Protected variable accessers */
#define super_objs(obj) (((const struct ArrayStack*)(obj))->objs)
#define super_len(obj) (((const struct ArrayStack*)(obj))->len)
#define super_size(obj) (((const struct ArrayStack*)(obj))->size)
#define super_type(obj) (((const struct ArrayStack*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ArrayStackClass{
    /* Class that is being extended */
    const struct StackClass _;

    void* (*_resize)();
    void* (*caller_resize)();
    void* (*this_resize)(void* self, int size);


    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);
};

void* _super_resize(struct Object* class, void* self, ...);
#define super_resize(class, self, ...) _super_resize(class, self, ##__VA_ARGS__, FUNC_END)
/** END Method management **/


/* Class builder */
const void* const ArrayStackClass();

#endif //OOC_ArrayStack// _R
