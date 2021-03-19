#ifndef OOC_DOUBLE_R
#define OOC_DOUBLE_R

#include "PrimWrapper.r"

struct Double{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    double data;
};

#endif //OOC_DOUBLE_R