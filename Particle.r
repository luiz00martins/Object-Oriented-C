#ifndef OOC_Particle_R
#define OOC_Particle_R

#include "OOC Library/Object.r"

/** START Variable manegement **/
/* Object constructor structure */
struct Particle{
    /* Object that is being extended */
    const struct Object _;

    struct LongDouble* position[3];
    struct LongDouble* momentum[3];
};

/* Public and Protected variable accessers */
#define super_name(obj) (((const struct Particle*)(obj))->name)
#define super_age(obj) (((const struct Particle*)(obj))->age)
#define super_height(obj) (((const struct Particle*)(obj))->height)

/* Protected and Private variable setters (optional) */
/** END Variable manegement **/

/** START Method management **/
/* Class constructor structure */
struct ParticleClass{
    /* Class that is being extended */
    const struct Class _;

    void* (*_print)();
    void* (*caller_print)();
    void* (*this_print)(void* self);

    void* (*_printBound)();
    void* (*caller_printBound)();
    void* (*this_printBound)(void* self, int bound);

    void* (*_scan)();
    void* (*caller_scan)();
    void* (*this_scan)(void* self);
};

/* Super callers */
void* _super_print(struct Class* class, void* self, ...);
#define super_print(class, self, ...) _super_print(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_printBound(struct Class* class, void* self, ...);
#define super_printBound(class, self, ...) _super_printBound(class, self, ##__VA_ARGS__, FUNC_END)
void* _super_scan(struct Class* class, void* self, ...);
#define super_scan(class, self, ...) _super_scan(class, self, ##__VA_ARGS__, FUNC_END)

/** END Method management **/


/* Class builder */
const void* const ParticleClass();

#endif //OOC_Particle_R
