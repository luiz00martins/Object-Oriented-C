#ifndef OOC_Queue_H
#define OOC_Queue_H

#include "../Object.h"

#define peek(self, ...) callMethod("peek", self, __VA_ARGS__)
#define push(self, ...) callMethod("push", self, __VA_ARGS__)
#define pop(self, ...) callMethod("pop", self, __VA_ARGS__)
#define clear(self, ...) callMethod("clear", self, __VA_ARGS__)
#define resize(self, ...) callMethod("resize", self, __VA_ARGS__)
#define contains(self, ...) callMethod("contains", self, __VA_ARGS__)
#define indexOf(self, ...) callMethod("indexOf", self, __VA_ARGS__)
#define ofType(self, ...) callMethod("ofType", self, __VA_ARGS__)

pointer Queue();

#endif //OOC_Queue_H
