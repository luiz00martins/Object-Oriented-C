#ifndef OOC_ArrayList_H
#define OOC_ArrayList_H

#include "List.h"

#define resize(self, ...) callMethod("resize", self, __VA_ARGS__)
#define print(self, ...) callMethod("print", self, __VA_ARGS__)

pointer ArrayList();

#endif //OOC_ArrayList_H

