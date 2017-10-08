#ifndef ENTITY_H
#define ENTITY_H

#include "etc/color.h"
#include "graphics/sprite.h"

class Entity
{
public:
    Entity();
    Entity(Sprite *spt, float x = 0., float y = 0.);
    virtual Entity copy();
    virtual Sprite *getSprite();
    virtual void setCoordinates(float x, float y);
    virtual void getCoordinates(float *x, float *y);
    virtual void move(float x, float y);

protected:
    float _x, _y;
    Sprite *_sprite;
};

#endif // ENTITY_H
