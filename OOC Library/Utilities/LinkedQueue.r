#ifndef OOC_LinkedQueue_R
#define OOC_LinkedQueue_R

#include "Queue.r"

typedef struct LinkedNode {
    void* obj;
    struct LinkedNode* next;
} LinkedNode;

/** START Variable manegement **/
/* Object constructor structure */
struct LinkedQueue{
    /* Object that is being extended */
    const struct Queue _;

    LinkedNode* head;
    int len;
    struct Class* type;
};

/* Public and Protected variable accessers */
#define super_head(obj) (((const struct LinkedQueue*)(obj))->head)
#define super_len(obj) (((const struct LinkedQueue*)(obj))->len)
#define super_type(obj) (((const struct ArrayQueue*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LinkedQueueClass{
    /* Class that is being extended */
    const struct QueueClass _;

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);
};

/** END Method management **/


/* Class builder */
const void* const LinkedQueueClass();

#endif //OOC_LinkedQueue// _R
