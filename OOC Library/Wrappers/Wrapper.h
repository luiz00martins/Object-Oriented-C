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

#define wrap(target) _Generic((target), \
\
    char: new(Char(), &target, sizeof(char)), \
    short: new(Short(), &target, sizeof(short)), \
    int: new(Int(), &target, sizeof(int)), \
    long: new(Long(), &target, sizeof(long)), \
    long long: new(LongLong(), &target, sizeof(long long)), \
    float: new(Float(), &target, sizeof(float)), \
    double: new(Double(), &target, sizeof(double)), \
    long double: new(LongDouble(), &target, sizeof(long double)), \
    void *: new(Ptr(), &target, sizeof(void*)))

#define unwrap(self, target) _unwrap(self, &target, sizeof(target))
/** END Method manegement **/

/* Object builder */
const void* const Wrapper();

#endif //OOC_WRAPPER_H
