#ifndef OOC_LinkedStack_R
#define OOC_LinkedStack_R

#include "Stack.r"

typedef struct LinkedNode {
    struct Object* obj;
    struct LinkedNode* next;
} LinkedNode;

/** START Variable manegement **/
/* Object constructor structure */
struct LinkedStack{
    /* Object that is being extended */
    const struct Stack _;

    LinkedNode* head;
    int len;
    class type;
};

/* Public and Protected variable accessers */
#define super_head(obj) (((const struct LinkedStack*)(obj))->head)
#define super_len(obj) (((const struct LinkedStack*)(obj))->len)
#define super_type(obj) (((const struct LinkedQueue*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LinkedStackClass{
    /* Class that is being extended */
    const struct StackClass _;

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);
};

/** END Method management **/


/* Class builder */
const void* const LinkedStackClass();

#endif //OOC_LinkedStack// _R
