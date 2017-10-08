#include "character.h"

Character::Character()
{

}

Character::Character(Sprite *spt, float x, float y)
{

}

bool Character::isAlive()
{
    return _health == 0;
}

uint Character::getHealth()
{
    return _health;
}

void Character::heal(uint amount)
{

}

void Character::charge(uint amount)
{

}

void Character::damage(uint amount)
{

}
