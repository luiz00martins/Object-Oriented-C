
#ifndef OBJECT_H
#define OBJECT_H

#include <stdarg.h>
#include "bool.h"

void* new(const void* _class, ...);
void delete(void* self);

const struct Class* getClass(const void* self);
int sizeOf(const void* self);
bool is_class(const void* self, const struct Class* class);
bool of_class(const void* self, const struct Class* class);

const struct Class* Class;
const struct Object* Object;

#endif //OBJECT_H
