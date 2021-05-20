
#include <stdlib.h>
#include <stdio.h>
#include <assert.h>
#include "BinaryTreeNode.h"
#include "BinaryTreeNode.r"
#include "../Wrappers/PrimWrapper.h"

#define CLASS_NAME BinaryTreeNode
newClass(Object,
    (default, ctor),
    (default, dtor),
    (default, add),
    (default, remove),
    (default, clear),
    (default, contains),
    (default, print),
    (default, printInOrder),
    (default, printPreOrder),
    (default, printPostOrder)
)

/* Overloaded: */
define_method(ctor){
    param(Object, obj);
    callSuperMethod(args);

    // Gathering arguments
    self->obj = obj;

    self->left = NULL;
    self->right = NULL;

    returning(BinaryTreeNode, self);
}
define_method(dtor){
    callSuperMethod();

    if (self->left != NULL) {
        delete(self->left);
    }
    else if (self->right != NULL) {
        delete(self->right);
    }

    returning(BinaryTreeNode, self);
}
define_method(add){
    param(Object, obj);

    if (as(bool, equals(self->obj, obj))) {
        // Pass.
    }
    else if(as(bool, greaterThan(self->obj, obj))){           
        if (self->left == NULL)
            self->left = new(BinaryTreeNode, obj);
        else
            add(self->left, obj);
    }
    else {
        if (self->right == NULL)
            self->right = new(BinaryTreeNode, obj);
        else
            add(self->right, obj);
    }

    returning();
}
define_method(remove){
    param(Object, obj);

    if (as(bool, equals(self->obj, obj))) {
        if (self->left == NULL && self->right == NULL) {
            int returned = 2;
            returning(int, returned);
        }
    }
    else {
        int returned;
        if (as(bool, greaterThan(self->obj, obj))) {
            returned = as(int, remove(self->left, obj));
            if (returned == 2) {

            }
        }
        else {
            if (self->right == NULL)
                self->right = new(BinaryTreeNode, obj);
            else
                add(self->right, obj);
        }
    }
}
define_method(clear){

    if (self->left != NULL) {
        delete(self->left);
        self->left = NULL;
    }
    else if (self->right != NULL) {
        delete(self->right);
        self->right = NULL;
    }
    returning();
}
define_method(contains){
    param(Object, obj);

    bool returned = true;

    if (as(bool, equals(self->obj, obj))) {
        returning(bool, returned);
    }
    else if (as(bool, greaterThan(self->obj, obj))) {
        if (self->left != NULL) {
            returned = as(bool, contains(self->left, obj));
            returning(bool, returned);
        }
    }
    else {
        if (self->right != NULL) {
            returned = as(bool, contains(self->right, obj));
            returning(bool, returned);
        }
    }

    returned = false;
    returning(bool, returned);
}
define_method(print){
    param(int, bound);

    printBound(self->obj, bound);

    returning();
}
define_method(printInOrder){
    param(int, bound);

    if (self->left != NULL)
        printInOrder(self->left, bound);
    print(self, bound);
    printf("\n");
    if (self->right != NULL)
        printInOrder(self->right, bound);

    returning();
}
define_method(printPreOrder){
    param(int, bound);

    print(self, bound);
    printf("\n");
    if (self->left != NULL)
        printPreOrder(self->left, bound);
    if (self->right != NULL)
        printPreOrder(self->right, bound);

    returning();
}
define_method(printPostOrder){
    param(int, bound);

    if (self->left != NULL)
        printPostOrder(self->left, bound);
    if (self->right != NULL)
        printPostOrder(self->right, bound);
    print(self, bound);
    printf("\n");

    returning();
}
