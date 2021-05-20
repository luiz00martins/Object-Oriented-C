#ifndef OOC_ArrayQueue_R
#define OOC_ArrayQueue_R

#include "Queue.r"

/** START Variable manegement **/
/* Object constructor structure */
struct ArrayQueue{
    /* Object that is being extended */
    const struct Queue _;

    struct Object** objs;
    int len;
    int size;
    int start;
    int end;
    class type;
};

/* Public and Protected variable accessers */
#define super_objs(obj) (((const struct ArrayQueue*)(obj))->objs)
#define super_len(obj) (((const struct ArrayQueue*)(obj))->len)
#define super_size(obj) (((const struct ArrayQueue*)(obj))->size)
#define super_start(obj) (((const struct ArrayQueue*)(obj))->start)
#define super_end(obj) (((const struct ArrayQueue*)(obj))->end)
#define super_type(obj) (((const struct ArrayQueue*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ArrayQueueClass{
    /* Class that is being extended */
    const struct QueueClass _;

    void* (*_resize)();
    void* (*caller_resize)();
    void* (*this_resize)(void* self, int size);

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);
};

void* _super_resize(struct Object* class, void* self, ...);
#define super_resize(class, self, ...) _super_resize(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_print(struct Object* class, void* self, ...);
#define super_print(class, self, ...) _super_print(class, self, ##__VA_ARGS__, FUNC_END)
/** END Method management **/


/* Class builder */
const void* const ArrayQueueClass();

#endif //OOC_ArrayQueue// _R
