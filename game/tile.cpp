#include "tile.h"

Tile::Tile()
{

}

Tile::Tile(Sprite *sprite, bool walkable, bool seethrough, bool interactable)
{
    _sprite = sprite;
    _walkable = walkable;
    _interactable = seethrough;
    _seethrough = interactable;
}

bool Tile::IsWalkable()
{
    return _walkable;
}

bool Tile::IsSeeThrough()
{
    return _seethrough;
}

bool Tile::IsInteractable()
{
    return _interactable;
}

Sprite *Tile::getSprite()
{
    return _sprite;
}

bool Tile::interact()
{
    return false;
}
