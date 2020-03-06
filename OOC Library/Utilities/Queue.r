#ifndef OOC_Queue_R
#define OOC_Queue_R

#include "../Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Queue{
    /* Object that is being extended */
    const struct Object _;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct QueueClass{
    /* Class that is being extended */
    const struct Class _;

    void* (*_peek)();
    void* (*caller_peek)();
    void* (*this_peek)(void* self);

    void* (*_push)();
    void* (*caller_push)();
    void* (*this_push)(void* self, void* obj);

    void* (*_pop)();
    void* (*caller_pop)();
    void* (*this_pop)(void* self);

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
void* _super_peek(struct Class* class, void* self, ...);
#define super_peek(class, self, ...) _super_peek(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_push(struct Class* class, void* self, ...);
#define super_push(class, self, ...) _super_push(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_pop(struct Class* class, void* self, ...);
#define super_pop(class, self, ...) _super_pop(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_clear(struct Class* class, void* self, ...);
#define super_clear(class, self, ...) _super_clear(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_contains(struct Class* class, void* self, ...);
#define super_contains(class, self, ...) _super_contains(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_indexOf(struct Class* class, void* self, ...);
#define super_indexOf(class, self, ...) _super_indexOf(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_ofType(struct Class* class, void* self, ...);
#define super_ofType(class, self, ...) _super_ofType(class, self, ##__VA_ARGS__, FUNC_END)

/** END Method management **/


/* Class builder */
const void* const QueueClass();

#endif //OOC_Queue_R
