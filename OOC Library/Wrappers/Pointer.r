#ifndef OOC_POINTER_R
#define OOC_POINTER_R

#include "PrimWrapper.r"

struct Pointer{
    /* Object that is being extended */
    const struct PrimWrapper _;
    // Data:
    void* data;
};

#endif //OOC_POINTER_R