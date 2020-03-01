#ifndef OOC_String_H
#define OOC_String_H

#include "../Object.h"

/** START Variable manegement **/
/* Public variable getters & setters */
build_decl_get(i);
build_decl_set(i);
build_decl_get(f);
build_decl_set(f);
build_decl_get(c);
build_decl_set(c);
build_decl_get(ptrC);
build_decl_set(ptrC);

/* Protected and Private variable getters (optional) */
build_decl_get(protI);
build_decl_get(protF);
build_decl_get(protC);
build_decl_get(privI);
build_decl_get(privF);
build_decl_get(privC);
/** END Variable manegement **/

/* START Method manegement **/
// new(String, int i, float f, char c, int protI, float protF, char protC)
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
