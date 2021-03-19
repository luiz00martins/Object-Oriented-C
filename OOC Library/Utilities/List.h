#ifndef OOC_List_H
#define OOC_List_H

#include "../Object.h"

#define get(self, ...) callMethod("get", self, __VA_ARGS__)
#define add(self, ...) callMethod("add", self, __VA_ARGS__)
#define remove(self, ...) callMethod("remove", self, __VA_ARGS__)
#define push(self, ...) callMethod("push", self, __VA_ARGS__)
#define pop(self, ...) callMethod("pop", self, __VA_ARGS__)
#define clear(self, ...) callMethod("clear", self, __VA_ARGS__)
#define contains(self, ...) callMethod("contains", self, __VA_ARGS__)
#define indexOf(self, ...) callMethod("indexOf", self, __VA_ARGS__)
#define ofType(self, ...) callMethod("ofType", self, __VA_ARGS__)

pointer List();

#endif //OOC_List_H
