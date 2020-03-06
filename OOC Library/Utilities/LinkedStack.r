#ifndef OOC_LinkedStack_R
#define OOC_LinkedStack_R

#include "Stack.r"

typedef struct LinkedNode {
    void* obj;
    struct LinkedNode* next;
} LinkedNode;

/** START Variable manegement **/
/* Object constructor structure */
struct LinkedStack{
    /* Object that is being extended */
    const struct Stack _;

    LinkedNode* head;
    int len;
    struct Class* type;
};

/* Public and Protected variable accessers */
#define super_head(obj) (((const struct LinkedStack*)(obj))->head)
#define super_len(obj) (((const struct LinkedStack*)(obj))->len)
#define super_type(obj) (((const struct ArrayStack*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LinkedStackClass{
    /* Class that is being extended */
    const struct StackClass _;
};

/** END Method management **/


/* Class builder */
const void* const LinkedStackClass();

#endif //OOC_LinkedStack// _R
