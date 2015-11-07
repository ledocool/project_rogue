#ifndef SPRITEMANAGER_H
#define SPRITEMANAGER_H

#include "stdafx.h"
#include "graphics/sprite.h"

class spriteManager// : public singleton <spriteManager>
{
public:
    spriteManager();
    ~spriteManager();

    bool regSprite(sprite *spt);
    bool unregSprite(sprite *spt);

    sprite* getspriteByNumber(uint i);

private:
    std::vector <sprite *> sprite_array;

};

#endif // SPRITEMANAGER_H
