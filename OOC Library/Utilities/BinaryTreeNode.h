#ifndef OOC_BinaryTreeNode_H
#define OOC_BinaryTreeNode_H

#include "../Object.h"

#define add(self, ...) callMethod("add", self, __VA_ARGS__)
#define remove(self, ...) callMethod("remove", self, __VA_ARGS__)
#define clear(self, ...) callMethod("clear", self, __VA_ARGS__)
#define contains(self, ...) callMethod("contains", self, __VA_ARGS__)
#define printInOrder(self, ...) callMethod("printInOrder", self, __VA_ARGS__)
#define printPreOrder(self, ...) callMethod("printPreOrder", self, __VA_ARGS__)
#define printPostOrder(self, ...) callMethod("printPostOrder", self, __VA_ARGS__)

pointer BinaryTreeNode();

#endif //OOC_BinaryTreeNode_H
