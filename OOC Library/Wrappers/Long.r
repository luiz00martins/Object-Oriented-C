#ifndef OOC_LONG_R
#define OOC_LONG_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Long{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LongClass{
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
const void* LongClass();

#endif //OOC_LONG_R