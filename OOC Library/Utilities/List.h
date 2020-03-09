#ifndef OOC_List_H
#define OOC_List_H

#include "../Object.h"

/** START Variable manegement **/
/* Public variable getters & setters */

/* Protected and Private variable getters (optional) */
/** END Variable manegement **/

/** START Method manegement **/

void* _get(void* self, ...);
#define get(self, ...) _get(self, ##__VA_ARGS__, FUNC_END)
void* _set(void* self, ...);
#define set(self, ...) _set(self, ##__VA_ARGS__, FUNC_END)
void* _remove(void* self, ...);
#define remove(self, ...) _remove(self, ##__VA_ARGS__, FUNC_END)
void* _push(void* self, ...);
#define push(self, ...) _push(self, ##__VA_ARGS__, FUNC_END)
void* _pop(void* self, ...);
#define pop(self, ...) _pop(self, ##__VA_ARGS__, FUNC_END)
void* _clear(void* self, ...);
#define clear(self, ...) _clear(self, ##__VA_ARGS__, FUNC_END)
void* _contains(void* self, ...);
#define contains(self, ...) _contains(self, ##__VA_ARGS__, FUNC_END)
void* _indexOf(void* self, ...);
#define indexOf(self, ...) _indexOf(self, ##__VA_ARGS__, FUNC_END)
void* _ofType(void* self, ...);
#define ofType(self, ...) _ofType(self, ##__VA_ARGS__, FUNC_END)

/** END Method manegement **/

/* Object builder */
const void* const List();

#endif //OOC_List_H
