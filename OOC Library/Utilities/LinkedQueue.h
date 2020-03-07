#ifndef OOC_LinkedQueue_H
#define OOC_LinkedQueue_H

#include "Queue.h"

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
const void* const LinkedQueue();

#endif //OOC_LinkedQueue_H
