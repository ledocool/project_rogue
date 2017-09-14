#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "stdafx.h"
#include "graphics/sprite.h"

class Sprite;

class SpriteManager// : public singleton <spriteManager>
{
public:
    SpriteManager();
    ~SpriteManager();

    bool regSprite(Sprite *spt);
    bool unregSprite(Sprite *spt);

    Sprite* getspriteByNumber(uint i);

private:
    std::vector <Sprite *> _sprite_array;

};

#endif // SPRITEMANAGER_H
