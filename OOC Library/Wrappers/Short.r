#ifndef OOC_SHORT_R
#define OOC_SHORT_R

#include "PrimWrapper.r"

struct Short{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    short data;
};

#endif //OOC_SHORT_R