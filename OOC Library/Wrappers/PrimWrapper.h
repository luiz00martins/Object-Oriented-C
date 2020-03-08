#ifndef OOC_PRIMWRAPPER_H
#define OOC_PRIMWRAPPER_H

#include "Wrapper.h"

/** START Variable manegement **/
/* Public variable getters & setters */

/* Protected and Private variable getters (optional) */

/** END Variable manegement **/

/** START Method manegement **/

void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)
void* _printBound(void* self, ...);
#define printBound(self, ...) _printBound(self, ##__VA_ARGS__, FUNC_END)
void* _scan(void* self, ...);
#define scan(self, ...) _scan(self, ##__VA_ARGS__, FUNC_END)

/** END Method manegement **/

/* Object builder */
const void* const PrimWrapper();

#endif //OOC_PRIMWRAPPER_H
