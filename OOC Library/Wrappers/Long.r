#ifndef OOC_LONG_R
#define OOC_LONG_R

#include "PrimWrapper.r"

struct Long{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long data;
};

#endif //OOC_LONG_R