#ifndef OOC_INT_R
#define OOC_INT_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Int{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    int data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct IntClass{
    /* Class that is being extended */
    const struct PrimWrapperClass _;

    /* Public: */

    /* Protected: */
};

/* Public super callers */

/* Protected function callers */

/* Protected super callers */
/** END Method management **/


/* Class builder */
const void* IntClass();

#endif //OOC_INT_R