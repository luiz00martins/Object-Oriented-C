#ifndef OOC_ArrayList_H
#define OOC_ArrayList_H

#include "List.h"

/** START Variable manegement **/
/* Public variable getters & setters */
build_decl_get(len);

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/** START Method manegement **/
void* _resize(void* self, ...);
#define resize(self, ...) _resize(self, ##__VA_ARGS__, FUNC_END)
void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)
/* Public method callers */

/** END Method manegement **/

/* Object builder */
const void* const ArrayList();

#endif //OOC_ArrayList_H
