#ifndef CHARACTER_H
#define CHARACTER_H

#include "entity.h"
#include "stdafx.h"

class Character : public Entity
{
public:
    Character();
    Character(Sprite *spt, float x = 0., float y = 0.);
    bool isAlive();
    uint getHealth();
    void heal(uint amount = 0);
    void charge(uint amount = 0);
    void damage(uint amount = 0);
    void discharge(uint amount = 0);

protected:
    uint _health, _energy, _healthCap, _eneryCap;
    std::vector<Entity *> inventory;

};

#endif // CHARACTER_H
