#ifndef TILE_H
#define TILE_H

#include "stdafx.h"

class Tile
{
public:
    Tile();
    Tile(Color clr);
    Tile(short r, short g, short b);
    void render(double x, double y);


public:
    Color _color;
};

#endif // TILE_H
