#ifndef OOC_PRIMWRAPPER_H
#define OOC_PRIMWRAPPER_H

#include "Wrapper.h"


#define ctor(self, ...) callMethod("ctor", self, __VA_ARGS__)
#define dtor(self, ...) callMethod("dtor", self, __VA_ARGS__)
#define get(self, ...) callMethod("get", self, __VA_ARGS__)
#define dataSize(self, ...) callMethod("dataSize", self, __VA_ARGS__)
#define print(self, ...) callMethod("print", self, __VA_ARGS__)
#define printBound(self, ...) callMethod("printBound", self, __VA_ARGS__)
#define scan(self, ...) callMethod("scan", self, __VA_ARGS__)
#define lessThan(self, ...) callMethod("lessThan", self, __VA_ARGS__)
#define greaterThan(self, ...) callMethod("greaterThan", self, __VA_ARGS__)

/* Object builder */
pointer PrimWrapper();

#endif //OOC_PRIMWRAPPER_H
