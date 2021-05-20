#ifndef OOC_BOOL_R
#define OOC_BOOL_R

#include "PrimWrapper.r"

struct Bool{
    const struct PrimWrapper _;
    // Data:
    bool data;
};

#endif //OOC_BOOL_R