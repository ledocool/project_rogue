#ifndef MAP_H
#define MAP_H
#include "stdafx.h"
#include "game/tile.h"


class map
{
public:
    map();
    map(uint w, uint h);

    //Used for level generation. Prpbably will call for an external generator
    void generate(uint w, uint h); //Generates level, specified by height and width
    void clear(); //Emty map;

protected:
    //TODO: add friggin square class that has all info on map square;
    uint width, height; //Width and height o map in squares;
    std::vector < tile > playfield; //Substitute for map
    std::vector < int > entities; //Players, mobs, trees and items;
};

#endif // MAP_H
