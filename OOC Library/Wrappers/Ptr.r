#ifndef OOC_PTR_R
#define OOC_PTR_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Ptr{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    void* data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct PtrClass{
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
const void* PtrClass();

#endif //OOC_PTR_R