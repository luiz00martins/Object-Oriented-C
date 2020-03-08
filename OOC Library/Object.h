
#ifndef OOC_OBJECT_H
#define OOC_OBJECT_H

#include <stdarg.h>
#include <stdbool.h>
#include "OOC_Preprocessor.h"

void* new(const void* _class, ...);
void delete(void* self);
struct Object* copy(const void* self);

// Change all of these defines to inline functions
void* _deepcopy(void* self, ...);
#define deepcopy(self, ...) _deepcopy(self, ##__VA_ARGS__, FUNC_END)
void* _equals(void* self, ...);
#define equals(self, ...) _equals(self, ##__VA_ARGS__, FUNC_END)
/**
 * @param self Object or Class
 * @return Class of self
 */
const struct Class* getClass(const void* self);
/* Returns the size of the object, when used in an object.
 * Returns the size of the subclass or object created when used in a class */
int sizeOf(const void* self);
/* Returns true if the pointer points to a class */
bool isAClass(const void* ptr);
/* Returns true if the pointer points to a class */
bool isAnObject(const void* ptr);
/* Returns true if the object is of that exact class */
bool isClass(const void* self, const struct Class* class);
/* Returns true if the object is any subclass of that class */
bool ofClass(const void* self, const struct Class* class);
/* Returns self if it can be casted into class, terminates the program otherwise */
void* cast(const struct Class* class, const void* self);

const void* const Object();

#endif //OOC_OBJECT_H
