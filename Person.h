#ifndef OOC_Person_H
#define OOC_Person_H

#include "OOC Library/Object.h"

/** START Variable manegement **/

/** END Variable manegement **/

/* START Method manegement **/
// new(Person, int i, float f, char c, int protI, float protF, char protC)
/* Public method callers */
void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)
void* _printBound(void* self, ...);
#define printBound(self, ...) _printBound(self, ##__VA_ARGS__, FUNC_END)
void* _scan(void* self, ...);
#define scan(self, ...) _scan(self, ##__VA_ARGS__, FUNC_END)
/** END Method manegement **/

/* Object builder */
const void* const Person();

#endif //OOC_Person_H
