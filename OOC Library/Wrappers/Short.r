#ifndef OOC_SHORT_R
#define OOC_SHORT_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Short{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    short data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ShortClass{
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
const void* ShortClass();

#endif //OOC_SHORT_R