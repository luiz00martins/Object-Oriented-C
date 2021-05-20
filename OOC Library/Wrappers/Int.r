#ifndef OOC_INT_R
#define OOC_INT_R

#include "PrimWrapper.r"

struct Int{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    int data;
};

#endif //OOC_INT_R