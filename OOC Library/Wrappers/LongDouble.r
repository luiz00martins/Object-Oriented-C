#ifndef OOC_LONGDOUBLE_R
#define OOC_LONGDOUBLE_R

#include "PrimWrapper.r"

struct LongDouble{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long double data;
};

#endif //OOC_LONGDOUBLE_R