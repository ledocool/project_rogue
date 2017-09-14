#include "entity.h"

Entity::Entity()
{
    _color = Color(0., 0., 0.);
    _x = 0.;
    _y = 0.;
}

Entity::Entity(short r, short g, short b, float x, float y)
{
    _color = Color(r, g, b);
    _x = x;
    _y = y;
}

void Entity::getCoordinates(float *x, float *y)
{
    *x = _x;
    *y = _y;
}

Entity Entity::copy()
{
    return Entity(_color.r, _color.g, _color.b, _x, _y);
}
