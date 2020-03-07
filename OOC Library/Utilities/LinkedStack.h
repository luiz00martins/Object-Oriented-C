#ifndef OOC_LinkedStack_H
#define OOC_LinkedStack_H

#include "Stack.h"

/** START Variable manegement **/
/* Public variable getters & setters */
build_decl_get(len);

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/** START Method manegement **/
void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)

/** END Method manegement **/

/* Object builder */
const void* const LinkedStack();

#endif //OOC_LinkedStack_H
