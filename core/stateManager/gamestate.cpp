#include "gamestate.h"
#include <sstream>
#include "game/entity.h"
#include "game/tile.h"

GameState::GameState()
{
    mapX = 0;
    mapY = 0;
    mapW = 20;
    mapH = 20;
}

GameState::~GameState()
{

}

void GameState::render()
{
    graphicMan->resetMatrix(); //draw in screens coordinates;
    graphicMan->clear();
    graphicMan->moveTo(cameraMan->getX(),
                       cameraMan->getY());

    uint mw, mh;
    _map.getMapSize(&mw, &mh);
    int screenWidth, screenHeight;
    graphicMan->getSize(&screenWidth, &screenHeight);

    uint /*mOffsetX=0,
         mOffsetY=0,*/
         mSizeX=mapW,
         mSizeY=mapH; //x,y,width,height

    /*
     * leftCoord = cameraX - screenWidth/2
     * rightCoord = camersX + screenWidth/2
     *
     * assume mapOffsetX is 0;
     * then tileCoord / tileWidth = tileNumber
     * leftCoord / tileWidth = startingTileNumber
     */

    float rectWidth = 40, rectHeight = 40;
    int startingTileX, startingTileY, endTileX, endTileY;

    startingTileX = (-(cameraMan->getX())) / rectWidth;
    startingTileY = (-(cameraMan->getY())) / rectHeight;
    endTileX = (-(cameraMan->getX()) + screenWidth + rectWidth+rectHeight) / rectWidth;
    endTileY = (-(cameraMan->getY()) + screenHeight + rectHeight+rectHeight) / rectHeight;
    startingTileX = startingTileX < 0 ? 0 : startingTileX;
    startingTileY = startingTileY < 0 ? 0 : startingTileY;

    uint    cutsizeX = (endTileX - startingTileX) < 0 ? 0 : (endTileX - startingTileX),
            cutsizeY = (endTileY - startingTileY) < 0 ? 0 : (endTileY - startingTileY);

    cutsizeX = startingTileX + endTileX > mSizeX ? mSizeX - startingTileX : cutsizeX;
    cutsizeY = startingTileY + endTileY > mSizeY ? mSizeY - startingTileY : cutsizeY;

    std::vector<Tile> tiles = _map.getRenderingSquare(startingTileX, startingTileY, cutsizeX, cutsizeY);
    std::vector<Entity> entities = _map.getEntities(-(cameraMan->getX()), -(cameraMan->getY()),
                                                    -(cameraMan->getX()) + screenWidth, -(cameraMan->getY()) + screenHeight);

    int tilesize = tiles.size(), entitysize = entities.size();
    GLfloat offsetX, offsetY;

    //todo: iterator here
    for(int i=0; i<tilesize; i++)
    {
        uint
            y = i/cutsizeX,
            x = i%cutsizeX;
        offsetX = startingTileX * rectWidth;
        offsetY = startingTileY * rectHeight;

//        graphicMan->drawRect(offsetX + rectWidth * x,
//                             offsetY + rectHeight * y,
//                             rectWidth,
//                             rectHeight,
//                             tiles[i]._color.r,
//                             tiles[i]._color.g,
//                             tiles[i]._color.b,
//                             1.0, 1);

            graphicMan->drawSprite(tiles[i].getSprite(),
                                   offsetX + rectWidth * x,
                                   offsetY + rectHeight * y,
                                   1.0, 0.);
    }

    //todo: iterator here
    for(int i=0; i<entitysize; i++)
    {
        graphicMan->drawCircle(entities[i]._x, entities[i]._y,
                               10,
                               entities[i]._color.r,
                               entities[i]._color.g,
                               entities[i]._color.b,
                               1.0, 1);
    }

    graphicMan->swapBuffers();
}

void GameState::enter()
{
    _map = Map(mapW, mapH);

    Entity *p1, *p2, *p3;
    p1 = new Entity(255, 0, 0, 100, 200);
    p2 = new Entity(0, 255, 0, 20, 20);
    p3 = new Entity(0, 0, 255, 20, 200);

    _map.addEntity(p1);
    _map.addEntity(p2);
    _map.addEntity(p3);
}

void GameState::processLogic(Uint32 ms)
{
    //todo: Apply changes to game state and map;
    float addY = 0, addX = 0;

    if(inputMan->keyIsHeld(keys::GO_UP))
        addY = -0.5 * ms;
    if(inputMan->keyIsHeld(keys::GO_DOWN))
        addY = +0.5 * ms;
    if(inputMan->keyIsHeld(keys::GO_LEFT))
        addX = +0.5 * ms;
    if(inputMan->keyIsHeld(keys::GO_RIGHT))
        addX = -0.5 * ms;
    if(inputMan->keyIsHeld(keys::ZOOM_IN))
        cameraMan->setZoom(cameraMan->getZoom() + 0.01);
    if(inputMan->keyIsHeld(keys::ZOOM_OUT))
        cameraMan->setZoom(cameraMan->getZoom() - 0.01);

    cameraMan->move(addX, addY);
}

void GameState::pause()
{
    printf ("Imma pausing gamestate\n");
}

void GameState::resume()
{
    printf ("Imma resuming gamestate\n");
}

void GameState::exit()
{
    _map.clear();
}
