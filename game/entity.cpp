#include "entity.h"

Entity::Entity()
{
    _x = 0.f;
    _y = 0.f;
    _sprite = NULL;
}

Entity::Entity(Sprite *spt, float x, float y)
{
    _sprite = spt;
    _x = x;
    _y = y;
}

void Entity::getCoordinates(float *x, float *y)
{
    *x = _x;
    *y = _y;
}

void Entity::move(float x, float y)
{
    _x += x;
    _y += y;
}

Entity Entity::copy()
{
    return Entity(this->_sprite, this->_x, this->_y);
}

Sprite *Entity::getSprite()
{
    return _sprite;
}

void Entity::setCoordinates(float x, float y)
{
    _x = x;
    _y = y;
}
