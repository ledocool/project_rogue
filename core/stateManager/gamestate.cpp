#include "gamestate.h"
#include <sstream>

GameState::GameState()
{
    mapX = 0;
    mapY = 0;
    mapW = 12;
    mapH = 12;
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

    std::vector<Tile> tiles = _map.getRenderingSquare(  startingTileX,
                                                        startingTileY,
                                                        cutsizeX,
                                                        cutsizeY );

    int tilesize = tiles.size();
    uint y, x;
    GLfloat offsetX, offsetY;

    for(int i=0; i<tilesize; i++)
    {
        y = i/cutsizeX,
        x = i%cutsizeX;
        offsetX = startingTileX * rectWidth;
        offsetY = startingTileY * rectHeight;

        graphicMan->drawRect(offsetX + rectWidth * x,
                             offsetY + rectHeight * y,
                             rectWidth,
                             rectHeight,
                             tiles[i]._color.r,
                             tiles[i]._color.g,
                             tiles[i]._color.b,
                             1.0, 1);
    }

    graphicMan->swapBuffers();
}

void GameState::enter()
{
    _map = Map(mapW, mapH);
}

void GameState::processLogic(std::vector<playerAction> actions)
{
    //todo: Apply changes to game state and map;
    float addY = 0, addX = 0;
    for(uint i=0; i<actions.size(); i++)
    {
        if(actions[i] == keys::GO_UP)
            addY = -0.5;
        if(actions[i] == keys::GO_DOWN)
            addY = +0.5;
        if(actions[i] == keys::GO_LEFT)
            addX = +0.5;
        if(actions[i] == keys::GO_RIGHT)
            addX = -0.5;
        if(actions[i] == keys::ZOOM_IN)
            cameraMan->setZoom(cameraMan->getZoom() + 0.001);
        if(actions[i] == keys::ZOOM_OUT)
            cameraMan->setZoom(cameraMan->getZoom() - 0.001);

    }

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
