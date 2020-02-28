
#ifndef OOC_OBJECT_R
#define OOC_OBJECT_R

#include <string.h>
#include <stddef.h>
#include <assert.h>
#include <stdarg.h>
#include <stdbool.h>

struct Class {
    const struct Class* object;
    char* name;
    const struct Class* super;
    size_t size;
    void** dataGet;
    int* dataOffsets;
    int* dataSizes;
    bool abstract;

    /* Note: Needs to start with caller_ctor*/
    void* (*_ctor)();
    void* (*caller_ctor)();
    void* (*this_ctor)(void* self, va_list* args);

    void* (*_dtor)();
    void* (*caller_dtor)();
    void* (*this_dtor)();

    void* (*_deepcopy)();
    void* (*caller_deepcopy)(void* self);
    void* (*this_deepcopy)(void* self);
};

struct Object {
    const struct Class* class;
};

#define FUNC_END_LONG_LONG 138698154113960401L
#define FUNC_END_LONG_DOUBLE 138698154113960402.0L
#define FUNC_END_DOUBLE 1386981541139603.0
#define FUNC_END FUNC_END_LONG_LONG, FUNC_END_LONG_DOUBLE, FUNC_END_DOUBLE

/**
 * @param self Class
 * @return Super of the class
 */
const void* super(const void* self);
void* abstract(const void* self, va_list *args);

/** START Method management **/
/* Protected function callers */
void* _ctor(void* self, ...);
void* _dtor(void* self, ...);
void* _deepcopy(void* self, ...);
#define ctor(self, ...) _ctor(self, ##__VA_ARGS__, FUNC_END)
#define dtor(self, ...) _dtor(self, ##__VA_ARGS__, FUNC_END)
#define deepcopy(self, ...) _deepcopy(self, ##__VA_ARGS__, FUNC_END)

void* _super_ctor(struct Class* class, void* self, ...);
void* _super_dtor(struct Class* class, void* self, ...);
void* _super_deepcopy(struct Class* class, void* self, ...);
#define super_ctor(class, self, ...) _super_ctor(class, self, ##__VA_ARGS__, FUNC_END);
#define super_dtor(class, self, ...) _super_dtor(class, self, ##__VA_ARGS__, FUNC_END);
#define super_deepcopy(class, self, ...) _super_deepcopy(class, self, ##__VA_ARGS__, FUNC_END);
/** END Method management **/

/* Class builder */
const void* const Class();

/* Return buffer */
void* _buffer;

#define returning(VAR) _returning(&VAR, sizeof(VAR));

#endif //OOC_OBJECT_R
