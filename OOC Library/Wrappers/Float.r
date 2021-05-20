#ifndef OOC_FLOAT_R
#define OOC_FLOAT_R

#include "PrimWrapper.r"

struct Float{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    float data;
};

#endif //OOC_FLOAT_R