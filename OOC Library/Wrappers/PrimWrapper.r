#ifndef OOC_PRIMWRAPPER_R
#define OOC_PRIMWRAPPER_R

#include "Wrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct PrimWrapper{
    /* Object that is being extended */
    const struct Wrapper _;
    // Data:

};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct PrimWrapperClass{
    /* Class that is being extended */
    const struct WrapperClass _;

    /* Public: */

    /* Protected: */

};

int directDataSize(void* wrapper);

/* Public super callers */

/* Protected function callers */

/* Protected super callers */
/** END Method management **/


/* Class builder */
const void* PrimWrapperClass();

#endif //OOC_PRIMWRAPPER_R