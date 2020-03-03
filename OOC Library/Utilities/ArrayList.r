#ifndef OOC_ArrayList_R
#define OOC_ArrayList_R

#include "List.r"

/** START Variable manegement **/
/* Object constructor structure */
struct ArrayList{
    /* Object that is being extended */
    const struct List _;

    void** objs;
    int len;
    int size;
};

/* Public and Protected variable accessers */
#define super_objs(obj) (((const struct ArrayList*)(obj))->objs)
#define super_len(obj) (((const struct ArrayList*)(obj))->len)
#define super_size(obj) (((const struct ArrayList*)(obj))->size)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ArrayListClass{
    /* Class that is being extended */
    const struct ListClass _;
};

/** END Method management **/


/* Class builder */
const void* const ArrayListClass();

#endif //OOC_ArrayList// _R
