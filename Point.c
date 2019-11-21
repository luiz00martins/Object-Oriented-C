
#include <assert.h>
#include <stdio.h>
#include "Point.h"
#include "Point.r"

/* START Caller functions */
/* HELPERS */
#define object_build_caller(FUNC, ARGS) \
    const struct PointClass* selfClass = ((const struct Object*)self)->class; \
    \
    assert(selfClass && selfClass->FUNC); \
    \
    return selfClass->FUNC ARGS

#define object_build_super_caller(FUNC, ARGS) \
    const struct PointClass* superclass = super(class); \
    \
    assert(self && superclass); \
    \
    return superclass->FUNC ARGS
/* HELPERS */

void move(void* self, double x, double y){
    object_build_caller(move, (self, x, y));
}
void super_move(const struct Class* class, void* self, double x, double y){
    object_build_super_caller(move, (self, x, y));
}

void draw(const void* self){
    object_build_caller(draw, (self));
}
void super_draw(const struct Class* class, const void* self){
    object_build_super_caller(draw, (self));
}

double getX(const void* self){
    object_build_caller(getX, (self));
}
double super_getX(const struct Class* class, const void* self){
    object_build_super_caller(getX, (self));
}

double getY(const void* self){
    object_build_caller(getY, (self));
}
double super_getY(const struct Class* class, const void* self){
    object_build_super_caller(getY, (self));
}
/* END Caller functions */

/* START Class function definitions */
void* PointClass_ctor(void* self, va_list* args){
    struct PointClass* classPtr = super_ctor(PointClass, self, args);
    typedef void (*voidf)(); /* generic function pointer */
    voidf selector;
    va_list funcArgs;

    va_copy(funcArgs, *args);
    /* Function overload function */
    while((selector = va_arg(*args, voidf))){
        voidf function = va_arg(*args, voidf);

        if (selector == move){
            classPtr->move = function;
        }
        else if (selector == draw) {
            classPtr->draw = function;
        }
        else if (selector == getX) {
            classPtr->getX = function;
        }
        else if (selector == getY) {
            classPtr->getY = function;
        }
    }
    va_end(funcArgs);

    return self;
}
/* END Class function definitions */

/* START Object function definitions */
void* Point_ctor(void* self, va_list* args){
    assert(self);

    struct Point* point = super_ctor(Point, self, args);

    point->x = va_arg(*args, double);
    point->y = va_arg(*args, double);

    return self;
}

void Point_move(void* self, double x, double y){
    assert(self);

    struct Point* point = self;

    point->x = x;
    point->y = y;
}

void Point_draw(const void* self){
    assert(self);

    const struct Point* point = self;

    printf("%.2lf %.2lf\n", point->x, point->y);
}

double Point_getX(const void* self){
    assert(self);

    const struct Point* point = self;

    return point->x;
}

double Point_getY(const void* self){
    assert(self);

    const struct Point* point = self;

    return point->y;
}
/* END Object function definitions */

/* START Initializer */
void initPoint(){
    if(!PointClass){
        PointClass = new(Class, "PointClass", Class, sizeof(struct PointClass),
                         ctor, PointClass_ctor,
                         0);
    }
    if(!Point){
        Point = new(PointClass, "Point", Object, sizeof(struct Point),
                    ctor, Point_ctor,
                    move, Point_move,
                    draw, Point_draw,
                    getX, Point_getX,
                    getY, Point_getY,
                    NULL);
    }
}
/* END Initializer */