#ifndef OOC_EXAMPLE_H
#define OOC_EXAMPLE_H

#include "OOC Library/Object.h"

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
// new(Example, int i, float f, char c, int protI, float protF, char protC)
/* Public method callers */
void* _print(void* self, ...);
#define print(self, ...) _print(self, ##__VA_ARGS__, FUNC_END)
void* _funcNoVar(void* self, ...);
#define funcNoVar(self, ...) _funcNoVar(self, ##__VA_ARGS__, FUNC_END)
void* _funcVar(void* self, ...);
#define funcVar(self, ...) _funcVar(self, ##__VA_ARGS__, FUNC_END)
/** END Method manegement **/

/* Object builder */
const void* const Example();

#endif //OOC_EXAMPLE_H
