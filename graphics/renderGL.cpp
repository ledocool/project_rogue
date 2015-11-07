#include "graphicmanager.h"

void graphicManager::render()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glScalef( cameraMan->getZoom(), cameraMan->getZoom(), 0);
    glTranslatef( cameraMan->getX(), cameraMan->getY(), 0 );  //moves scene;

    clear();

    sprite *spt = singleton <spriteManager> ::get()->getspriteByNumber(0);
    drawRect(10., 10., 20, 20, 1., 0., 0., 1., 1);
    if(spt != NULL)
        drawSprite(spt, 50, 50, 1.0f, 90.0f);

    drawLine(0, 0, 50, 50, 1., 0., 0., 1.);
    drawCircle(0, 0, 20, 1., 0., 0., 1.0, 1);

    swapBuffers();
}
