#ifndef OOC_String_H
#define OOC_String_H

#include "../Object.h"


#define print(self, ...) callMethod("print", self, __VA_ARGS__)
#define printBound(self, ...) callMethod("printBound", self, __VA_ARGS__)
#define scan(self, ...) callMethod("scan", self, __VA_ARGS__)
#define set(self, ...) callMethod("set", self, __VA_ARGS__)
#define asArray(self, ...) callMethod("asArray", self, __VA_ARGS__)
#define cat(self, ...) callMethod("cat", self, __VA_ARGS__)
#define resize(self, ...) callMethod("resize", self, __VA_ARGS__)
#define moreThan(self, ...) callMethod("moreThan", self, __VA_ARGS__)
#define lessThan(self, ...) callMethod("lessThan", self, __VA_ARGS__)

pointer String();

#endif //OOC_String_H
