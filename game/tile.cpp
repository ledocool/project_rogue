#include "tile.h"

Tile::Tile(){

}

Tile::Tile(Color c)
{
    _color = c;
}

Tile::Tile(short r, short g, short b)
{
    _color.b = b;
    _color.g = g;
    _color.r = r;
}

void Tile::render(double x, double y)
{

}
