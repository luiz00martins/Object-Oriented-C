#ifndef OOC_LinkedList_R
#define OOC_LinkedList_R

#include "List.r"

typedef struct LinkedNode {
    struct Object* obj;
    struct LinkedNode* next;
} LinkedNode;

/** START Variable manegement **/
/* Object constructor structure */
struct LinkedList{
    /* Object that is being extended */
    const struct List _;

    LinkedNode* head;
    int len;
    class type;
};

/* Public and Protected variable accessers */
#define super_head(obj) (((const struct LinkedList*)(obj))->head)
#define super_len(obj) (((const struct LinkedList*)(obj))->len)
#define super_type(obj) (((const struct LinkedList*)(obj))->type)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LinkedListClass{
    /* Class that is being extended */
    const struct ListClass _;

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);
};

/** END Method management **/


/* Class builder */
const void* const LinkedListClass();

#endif //OOC_LinkedList// _R
