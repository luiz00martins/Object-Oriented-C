#ifndef OOC_EXAMPLE_H
#define OOC_EXAMPLE_H

#include "OOC Library/Object.h"

// Public method
#define print(self, ...) callMethod("print", self, __VA_ARGS__)
#define funcNoVar(self, ...) callMethod("funcNoVar", self, __VA_ARGS__)
#define funcVar(self, ...) callMethod("funcVar", self, __VA_ARGS__)

pointer Example();

#endif //OOC_EXAMPLE_H
