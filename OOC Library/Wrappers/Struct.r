#ifndef OOC_STRUCT_R
#define OOC_STRUCT_R

#include "Wrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Struct{
    /* Object that is being extended */
    const struct Wrapper _;
    // Data:
    void* dataPtr;
    int size;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct StructClass{
    /* Class that is being extended */
    const struct WrapperClass _;

    /* Public: */

    /* Protected: */
};

/* Public super callers */

/* Protected function callers */

/* Protected super callers */
/** END Method management **/


/* Class builder */
const void* StructClass();

#endif //OOC_STRUCT_R