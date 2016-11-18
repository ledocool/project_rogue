#include "spritemanager.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
    for(uint i=0; i<sprite_array.size(); i++)
        delete sprite_array[i];
}

bool SpriteManager::regSprite(sprite *spt)
{
    for(uint i=0; i<sprite_array.size(); i++)
        if(sprite_array[i] == spt)
            return false;

    sprite_array.push_back(spt);
    return true;
}

bool SpriteManager::unregSprite(sprite *spt)
{
    for(uint i=0; i<sprite_array.size(); i++)
        if(sprite_array[i] == spt)
        {
            sprite *sp = sprite_array[i];
            sprite_array.erase(sprite_array.begin()+i);
            delete sp;

            return true;
        }

    return false;
}

sprite *SpriteManager::getspriteByNumber(uint i)
{
    if(i>=sprite_array.size())
        return NULL;

    return sprite_array[i];
}
