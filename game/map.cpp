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

Map::~Map()
{
    //uint entitySize = _entities.size();
    //remove all entities;
    //todo: iterator;
//    for(uint i=0; i < entitySize; i++)
//    {
//        delete _entities[i];
//    }
}

void Map::generate(uint w __attribute__((unused)), uint h __attribute__((unused)), uint seed __attribute__((unused)) = 0 )
{
    _playfield.resize(w*h);
    Sprite *wall, *floor;
    wall = new Sprite("tiles/wall.png");
    floor = new Sprite("tiles/floor.png");

    for(uint i=0; i<h; i++)
    {
        for(uint j=0; j<w; j++)
        {
            uint index = getItemIndex(j, i);

            if(i == 0 || i == h-1 || j == 0 || j == w-1)
            {
                _playfield[index] = Tile(wall, false, false, false);
            }else{
                _playfield[index] = Tile(floor, true, true, false);
            }
        }
    }

    Entity *bot = new Entity(new Sprite("./entities/characters/bot_green.png"), 40., 40.);
    _entities.push_back(bot);
    _playerEntity = bot;
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

std::vector<Entity> Map::getEntities(int x, int y, int xEd, int yEd)
{
    uint entityAmount = _entities.size();

    std::vector<Entity> result = std::vector<Entity>();
    result.reserve(entityAmount);
    for(int i=0; i<entityAmount; i++)
    {
        float entityX, entityY;
        _entities[i]->getCoordinates(&entityX, &entityY);
        if(entityX <= xEd && entityX >= x
                && entityY <= yEd && entityY >= y )
        {
            result.push_back(_entities[i]->copy());
        }
    }

    return result;
}

void Map::getMapSize(uint *w, uint *h)
{
    *w = _width;
    *h = _height;
}

Entity *Map::getPlayer()
{
    return _playerEntity;
}

bool Map::addEntity(Entity * e)
{
    _entities.push_back(e);
}

