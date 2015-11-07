#ifndef GRAPHICMANAGER_H
#define GRAPHICMANAGER_H

#include "stdafx.h"
#include "graphics/sprite.h"

#include "etc/camera.h"

class graphicManager// : singleton <graphicManager>
{
public:
    graphicManager();

    //Basic macro functions
    bool init(const char *title = "Default window",
              unsigned int x = 0, unsigned int y = 0,
              unsigned int height = 640, unsigned int width = 480);
    void render(); // works on rendring all that shit
    void freeAll();

    //Window size workers
    void getSize(int *w, int *h);
    void setSize(int w, int h);
    void resizeViewport();

    //simple draw functions
    void drawLine(GLfloat xSt, GLfloat ySt, GLfloat xEd, GLfloat yEd, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled = 1);
    void drawPixel(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, GLfloat a);
    void drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled = 1);

    void drawSprite(sprite *sp, GLfloat x, GLfloat y,
                    GLfloat scale, GLfloat rotation);

    void swapBuffers();
    void clear();

protected:
    //Buffer swap

private:
    //window micro
    bool makeWindow(const char *title, unsigned int x, unsigned int y, unsigned int height, unsigned int width);
    void destroyWindow();

    //Draw inits
    void initDraw(GLuint spr); //Inits texture;
    void setMatrix(GLfloat x, GLfloat y, GLfloat width, GLfloat height, float rotation); //For now it sets modelview matrix

    //GL micro
    void initGL(unsigned int h, unsigned int w);
    void freeGL();

    camera *cameraMan;

    SDL_Window *mainWindow;
    SDL_GLContext glcontext;
    GLuint currentSprite;
};

#endif // GRAPHICMANAGER_H