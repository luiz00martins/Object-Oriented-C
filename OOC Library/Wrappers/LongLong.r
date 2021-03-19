#ifndef OOC_LONGLONG_R
#define OOC_LONGLONG_R

#include "PrimWrapper.r"

struct LongLong{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    long long data;
};

#endif //OOC_LONGLONG_R