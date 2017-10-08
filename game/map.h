#ifndef MAP_H
#define MAP_H
#include "stdafx.h"
#include "game/tile.h"
#include "game/entity.h"


class Map
{
public:
    Map();
    Map(uint w, uint h);
    ~Map();
    //Used for level generation. Prpbably will call for an external generator
    void clear(); //Emty map;
    int getItemIndex(uint x, uint y);
    std::vector <Tile> getRenderingSquare(uint x, uint y, uint width, uint height);
    std::vector <Entity> getEntities(int x, int y, int xEd, int yEd);
    void getMapSize(uint *w, uint *h);
    Entity* getPlayer();
    bool addEntity(Entity *e);

private:
    //return -1 if outside range;
    /*Map tiles are stored in single array from top left corner (0,0) to bottom right corner (w,h)*/
    //Note: actually it starts at bottom left and stops at top right.
    /*    0   1  2  3  x
    * 0 | 0   1  2  3 |
    * 1 | 5   6  7  8 |
    * 2 | 9  10 11 12 |
    * 3 | 13 14 15 16 |
    * y
    * Index of the selected item would be found via formula:
    * f(x,y) = x + width*y;
    */
    //todo: remove me;
    void generate(uint w, uint h, uint seed); //Generates level, specified by height and width

    uint _width, _height; //Width and height o map in squares;
    std::vector < Tile > _playfield; //Substitute for map
    std::vector < Entity * > _entities; //Players, mobs, trees and items;
    Entity* _playerEntity;
};

#endif // MAP_H
