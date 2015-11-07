#include "map.h"

//Container for map

map::map()
{
    width = 0;
    height = 0;
}

map::map(uint w, uint h)
{
    generate(w,h);
}

void map::generate(uint w, uint h)
{
//    for(uint i=0; i<h; i++)
//    {
//        for(uint j=0; j<w; j++)
//            playfield[i][j] = ironBlock;
//    }
}

void map::clear()
{

}
