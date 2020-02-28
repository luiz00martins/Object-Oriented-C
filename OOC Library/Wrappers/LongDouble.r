#ifndef OOC_LONGDOUBLE_R
#define OOC_LONGDOUBLE_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct LongDouble{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long double data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LongDoubleClass{
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
const void* LongDoubleClass();

#endif //OOC_LONGDOUBLE_R