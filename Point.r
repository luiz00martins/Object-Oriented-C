#ifndef POINT_R
#define POINT_R

#include "Object.r"

struct PointClass{
    const struct Class _;
    void (*move)(void*, int, int);
    void (*draw)(const void*);
    double (*getX)(const void*);
    double (*getY)(const void*);
};

struct Point{
    const struct Object _;
    double x;
    double y;
};

#define super_x(point) (((const struct Point*)(point))->x)
#define super_y(point) (((const struct Point*)(point))->y)

void super_move(const struct Class* class, void* self, double x, double y);
void super_draw(const struct Class* class, const void* self);
double super_getX(const struct Class* class, const void* self);
double super_getY(const struct Class* class, const void* self);

#endif //POINT_R