#ifndef ENTITY_H
#define ENTITY_H

#include "etc/color.h"

class Entity
{
public:
    Entity();
    Entity(short r, short g, short b, float x = 0., float y = 0.);
    void getCoordinates(float *x, float *y);
    Entity copy();

public:
    Color _color;
    float _x, _y;
};

#endif // ENTITY_H
