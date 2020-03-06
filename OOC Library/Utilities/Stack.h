#ifndef OOC_Stack_H
#define OOC_Stack_H

#include "../Object.h"

/** START Variable manegement **/
/* Public variable getters & setters */

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/* START Method manegement **/

/* Public method callers */
void* _peek(void* self, ...);
#define peek(self, ...) _peek(self, ##__VA_ARGS__, FUNC_END)
void* _push(void* self, ...);
#define push(self, ...) _push(self, ##__VA_ARGS__, FUNC_END)
void* _pop(void* self, ...);
#define pop(self, ...) _pop(self, ##__VA_ARGS__, FUNC_END)
void* _clear(void* self, ...);
#define clear(self, ...) _clear(self, ##__VA_ARGS__, FUNC_END)
void* _resize(void* self, ...);
#define resize(self, ...) _resize(self, ##__VA_ARGS__, FUNC_END)
void* _contains(void* self, ...);
#define contains(self, ...) _contains(self, ##__VA_ARGS__, FUNC_END)
void* _indexOf(void* self, ...);
#define indexOf(self, ...) _indexOf(self, ##__VA_ARGS__, FUNC_END)
void* _ofType(void* self, ...);
#define ofType(self, ...) _ofType(self, ##__VA_ARGS__, FUNC_END)

/** END Method manegement **/

/* Object builder */
const void* const Stack();

#endif //OOC_Stack_H
