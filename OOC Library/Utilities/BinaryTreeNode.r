#ifndef OOC_BinaryTreeNode_R
#define OOC_BinaryTreeNode_R

#include "../Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct BinaryTreeNode{
    /* Object that is being extended */
    const struct Object _;

    struct Object* obj;
    struct BinaryTreeNode* left;
    struct BinaryTreeNode* right;
};

/* Public and Protected variable accessers */
#define super_obj(o) (((const struct BinaryTreeNode*)(o))->obj)
#define super_left(obj) (((const struct BinaryTreeNode*)(obj))->left)
#define super_right(obj) (((const struct BinaryTreeNode*)(obj))->right)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct BinaryTreeNodeClass{
    /* Class that is being extended */
    const struct Object _;

    void* (*_add)();
    void* (*caller_add)();
    void* (*this_add)(void* self, void* obj);

    void* (*_remove)();
    void* (*caller_remove)();
    void* (*this_remove)(void* self, void* obj);

    void* (*_clear)();
    void* (*caller_clear)();
    void* (*this_clear)(void* self);

    void* (*_contains)();
    void* (*caller_contains)();
    void* (*this_contains)(void* self);

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self, int bound);

    void* (*_printInOrder)();
    void* (*caller_printInOrder)();
    void* (*this_printInOrder)(void* self, int bound);

    void* (*_printPreOrder)();
    void* (*caller_printPreOrder)();
    void* (*this_printPreOrder)(void* self, int bound);

    void* (*_printPostOrder)();
    void* (*caller_printPostOrder)();
    void* (*this_printPostOrder)(void* self, int bound);
};

/** END Method management **/


/* Class builder */
const void* const BinaryTreeNodeClass();

#endif //OOC_BinaryTreeNode// _R
