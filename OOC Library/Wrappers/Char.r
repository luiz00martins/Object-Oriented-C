#ifndef OOC_CHAR_R
#define OOC_CHAR_R

#include "PrimWrapper.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Char{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    char data;
};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct CharClass{
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
const void* CharClass();

#endif //OOC_CHAR_R