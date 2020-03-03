#ifndef OOC_String_H
#define OOC_String_H

#include "../Object.h"

/** START Variable manegement **/
/* Public variable getters & setters */
build_decl_get(len);

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/* START Method manegement **/
/* Public method callers */
void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)
void* _set(void* self, ...);
#define set(self, ...) _set(self, ##__VA_ARGS__, FUNC_END)
void* _asArray(void* self, ...);
#define asArray(self, ...) _asArray(self, ##__VA_ARGS__, FUNC_END)
void* _cat(void* self, ...);
#define cat(self, ...) _cat(self, ##__VA_ARGS__, FUNC_END)
void* _resize(void* self, ...);
#define resize(self, ...) _resize(self, ##__VA_ARGS__, FUNC_END)
void* _compare(void* self, ...);
#define compare(self, ...) _compare(self, ##__VA_ARGS__, FUNC_END)

/** END Method manegement **/

/* Object builder */
const void* const String();

#endif //OOC_String_H
