
#ifndef OBJECT_R
#define OBJECT_R

#include <stddef.h>
#include <stdarg.h>
#include "bool.h"

struct Class {
    const struct Class* object;
    char* name;
    const struct Class* super;
    size_t size;

    void* (*ctor)(void* self, va_list* args);
    void* (*dtor)(void* self);
    bool (*is_class)(const void* self, const struct Class* class);
    bool (*of_class)(const void* self, const struct Class* class);
};

struct Object {
    const struct Class* class;
};

const void* super(const void* self);

void* ctor(void* self, va_list* args);
void* dtor(void* self);

void* super_ctor(const struct Class* class, void* self, va_list* args);
void* super_dtor(const struct Class* class, void* self);


#endif //OBJECT_R