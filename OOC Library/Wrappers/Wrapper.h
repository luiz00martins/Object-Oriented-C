#ifndef OOC_WRAPPER_H
#define OOC_WRAPPER_H

#include <assert.h>
#include "../Object.h"


/** START Variable manegement **/
/* Public variable getters & setters */

/* Protected and Private variable getters (optional) */

/** END Variable manegement **/

/* START Method manegement **/
// new(Wrapper()) = ERROR
/* Public method callers */
//void* _unwrap(void* self, void* target, unsigned int targetSize);
void* _unwrap(void* self, ...);
#define unwrap(SELF, TARGET) _unwrap(SELF, &TARGET, FUNC_END)

#define wrap(target) _Generic((target), \
    char: new(Char, target),\
    short: new(Short, target), \
    int: new(Int, target), \
    long: new(Long, target), \
    long long: new(LongLong, target), \
    float: new(Float, target), \
    double: new(Double, target), \
    long double: new(LongDouble, target), \
    _Bool: new(Bool, target), \
    class: new(Class, target), \
    pointer: new(Pointer, target))

/** END Method manegement **/

/* Object builder */
pointer Wrapper();

#endif //OOC_WRAPPER_H
