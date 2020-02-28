#ifndef OOC_DOUBLE_R
#define OOC_DOUBLE_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Double{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    double data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct DoubleClass{
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
const void* DoubleClass();

#endif //OOC_DOUBLE_R