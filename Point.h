//
// Created by luiz00martins on 14/10/19.
//

#ifndef CLASS_H
#define CLASS_H

#include "Object.h"

void move(void* self, double x, double y);
void draw(const void* self);
double getX(const void* self);
double getY(const void* self);

void initPoint();

const struct Class* PointClass;
const struct PointClass* Point;

#endif //CLASS_H
