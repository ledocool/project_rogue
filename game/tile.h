#ifndef TILE_H
#define TILE_H

#include "etc/color.h"
#include "graphics/sprite.h"

class Tile
{
public:
    Tile();
    Tile(Sprite *sprite, bool walkable, bool seethrough, bool interactable);

    bool IsWalkable();
    bool IsSeeThrough();
    bool IsInteractable();

    Sprite *getSprite();
    bool interact();

private:
    Sprite *_sprite;
    bool _walkable, _seethrough, _interactable;
};

#endif // TILE_H
