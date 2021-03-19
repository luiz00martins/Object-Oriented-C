#ifndef OOC_ArrayQueue_H
#define OOC_ArrayQueue_H

#include "Queue.h"

#define resize(self, ...) callMethod("resize", self, __VA_ARGS__)
#define print(self, ...) callMethod("print", self, __VA_ARGS__)

pointer ArrayQueue();

#endif //OOC_ArrayQueue_H
