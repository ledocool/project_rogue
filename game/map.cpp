#include "map.h"
#include "core/exception.h"

//Container for map

Map::Map()
{
    _width = 0;
    _height = 0;
}

Map::Map(uint w, uint h)
{
    _width = w;
    _height = h;
    generate(w,h,0);
}

void Map::generate(uint w __attribute__((unused)), uint h __attribute__((unused)), uint seed __attribute__((unused)) = 0 )
{
    _playfield.resize(w*h);
    for(uint i=0; i<h; i++)
    {
        for(uint j=0; j<w; j++){

            Color cl;
            if( (i+j) % 2 == 0){
                cl.r = 1.f;
                cl.g = 1.f;
                cl.b = 1.f;
            }else{
                cl.r = 0.f;
                cl.g = 0.f;
                cl.b = 0.f;
            }

            Tile tl(cl);
            _playfield[getItemIndex(j, i)] = tl;
        }
    }
}

void Map::clear()
{
    _playfield.clear();
    _entities.clear();
}

int Map::getItemIndex(uint x, uint y)
{
    if(x>=_width || y>=_height) return -1;
    return x + y*_width;
}

std::vector <Tile> Map::getRenderingSquare(uint x, uint y, uint width, uint height)
{
    if(x >= _width || y >= _height || x+width > _width || y+height > _height || x+width < 0 || y+height < 0)
    {
        return std::vector<Tile>();
    }

    std::vector<Tile> rets;
    rets.resize(width*height);

    int k=0;
    for(int i=0; i<height; i++)
    {
        for(int j=0; j<width; j++)
        {
            if(getItemIndex(x+j, y+i) >= _playfield.size() )
            {
                throw BasicException("Error cutting playfield", errorCodes::noError);
            }
            rets[k++] = _playfield[getItemIndex(x+j, y+i)];
        }
    }

    return rets;
}

void Map::getMapSize(uint *w, uint *h)
{
    *w = _width;
    *h = _height;
}

