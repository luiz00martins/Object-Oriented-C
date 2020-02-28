#ifndef OOC_WRAPPER_R
#define OOC_WRAPPER_R

#include "../Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Wrapper{
    /* Object that is being extended */
    const struct Object _;
    // Data:

};

/* Public and Protected variable accessers */

/* Protected and Private variable setters (optional) */

/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct WrapperClass{
    /* Class that is being extended */
    const struct Class _;

    /* Public: */
    void* (*_unwrap)();
    void* (*caller_unwrap)();
    void* (*this_unwrap)(void* self, void* target);

    /* Protected: */
    void* (*_dataSize)();
    void* (*caller_dataSize)();
    void* (*this_dataSize)(void* self);
};

/* Public super callers */

/* Protected function callers */
void* _dataSize(void* self, ...);
#define dataSize(self, ...) user_call(int, dataSize, ##__VA_ARGS__)

/* Protected super callers */
void* super_dataSize(struct Class* class, void* self, ...);
void super__unwrap(struct Class* class, void* target, void* self);
/** END Method management **/

/* Class builder */
const void* WrapperClass();

#endif //OOC_WRAPPER_R
