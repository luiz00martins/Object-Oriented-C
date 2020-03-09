#ifndef OOC_LinkedList_H
#define OOC_LinkedList_H

#include "List.h"

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
const void* const LinkedList();

#endif //OOC_LinkedList_H
