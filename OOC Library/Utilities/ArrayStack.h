#ifndef OOC_ArrayStack_H
#define OOC_ArrayStack_H

#include "Stack.h"

#define resize(self, ...) callMethod("resize", self, __VA_ARGS__)
#define print(self, ...) callMethod("print", self, __VA_ARGS__)

pointer ArrayStack();

#endif //OOC_ArrayStack_H