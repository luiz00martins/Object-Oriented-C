#ifndef OOC_ArrayStack_H
#define OOC_ArrayStack_H

#include "Stack.h"

/** START Variable manegement **/
/* Public variable getters & setters */
build_decl_get(len);

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/** START Method manegement **/
void* _resize(void* self, ...);
#define resize(self, ...) _resize(self, ##__VA_ARGS__, FUNC_END)
/** END Method manegement **/

/* Object builder */
const void* const ArrayStack();

#endif //OOC_ArrayStack_H