#ifndef OOC_FLOAT_R
#define OOC_FLOAT_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Float{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    float data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct FloatClass{
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
const void* FloatClass();

#endif //OOC_FLOAT_R