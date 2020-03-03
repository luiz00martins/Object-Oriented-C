#ifndef OOC_LinkedList_R
#define OOC_LinkedList_R

#include "List.r"

typedef struct LinkedNode {
    void* obj;
    struct LinkedNode* next;
} LinkedNode;

/** START Variable manegement **/
/* Object constructor structure */
struct LinkedList{
    /* Object that is being extended */
    const struct List _;

    LinkedNode* nodes;
    int len;
};

/* Public and Protected variable accessers */
#define super_nodes(obj) (((const struct LinkedList*)(obj))->nodes)
#define super_len(obj) (((const struct LinkedList*)(obj))->len)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LinkedListClass{
    /* Class that is being extended */
    const struct ListClass _;
};

/** END Method management **/


/* Class builder */
const void* const LinkedListClass();

#endif //OOC_LinkedList// _R
