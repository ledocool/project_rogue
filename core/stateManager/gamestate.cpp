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
    int screenWidth, screenHeight;
    graphicMan->getSize(&screenWidth, &screenHeight);
    graphicMan->resetMatrix(); //draw in screens coordinates;
    graphicMan->clear();
    graphicMan->moveTo(cameraMan->getX(),
                       cameraMan->getY());

    uint mw, mh;
    _map.getMapSize(&mw, &mh);
    int /*mOffsetX=0,
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
        graphicMan->drawSprite(tiles[i].getSprite(),
                               offsetX + rectWidth * x,
                               offsetY + rectHeight * y,
                               1.0, 0.);
    }

    //todo: iterator here
    for(int i=0; i<entitysize; i++)
    {
        float x, y;
        Sprite *spt;
        entities[i].getCoordinates(&x, &y);
        spt = entities[i].getSprite();
        graphicMan->drawSprite(spt, x, y, 1., 0.);
    }

    graphicMan->swapBuffers();
}

void GameState::enter()
{
    _map = Map(mapW, mapH);
    //todo: create player entity;
    //todo: populate map with entities;
}

void GameState::processLogic(Uint32 ms)
{
    int screenWidth, screenHeight;
    graphicMan->getSize(&screenWidth, &screenHeight);
    //todo: Apply changes to game state and map;
    float addY = 0, addX = 0;

    Entity *player =_map.getPlayer();

    if(inputMan->keyIsDown(keys::GO_UP))
        player->move(0, 40);
        //addY = -0.5 * ms;
    if(inputMan->keyIsDown(keys::GO_DOWN))
        player->move(0, -40);
        //addY = +0.5 * ms;
    if(inputMan->keyIsDown(keys::GO_LEFT))
        player->move(-40, 0);
        //addX = +0.5 * ms;
    if(inputMan->keyIsDown(keys::GO_RIGHT))
        player->move(40, 0);
        //addX = -0.5 * ms;
    if(inputMan->keyIsHeld(keys::ZOOM_IN))
        cameraMan->setZoom(cameraMan->getZoom() + 0.01);
    if(inputMan->keyIsHeld(keys::ZOOM_OUT))
        cameraMan->setZoom(cameraMan->getZoom() - 0.01);

    player->getCoordinates(&addX, &addY);
    cameraMan->set(-addX + screenWidth/2, -addY + screenHeight/2);
    //std::cout << "Man: " << addX << " " << addY << " Camera: " << addX*40 << " " << addY*40 << std::endl;
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
