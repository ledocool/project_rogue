#include "spritemanager.h"

SpriteManager::SpriteManager()
{

}

SpriteManager::~SpriteManager()
{
    for(uint i=0; i<_sprite_array.size(); i++)
        delete _sprite_array[i];
}

bool SpriteManager::regSprite(Sprite *spt)
{
    for(uint i=0; i<_sprite_array.size(); i++)
        if(_sprite_array[i] == spt)
            return false;

    _sprite_array.push_back(spt);
    return true;
}

bool SpriteManager::unregSprite(Sprite *spt)
{
    for(uint i=0; i<_sprite_array.size(); i++)
        if(_sprite_array[i] == spt)
        {
            Sprite *sp = _sprite_array[i];
            _sprite_array.erase(_sprite_array.begin()+i);
            delete sp;

            return true;
        }

    return false;
}

Sprite *SpriteManager::getspriteByNumber(uint i)
{
    if(i>=_sprite_array.size())
        return NULL;

    return _sprite_array[i];
}
