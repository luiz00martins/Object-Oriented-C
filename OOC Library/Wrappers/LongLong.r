#ifndef OOC_LONGLONG_R
#define OOC_LONGLONG_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct LongLong{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long long data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct LongLongClass{
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
const void* LongLongClass();

#endif //OOC_LONGLONG_R