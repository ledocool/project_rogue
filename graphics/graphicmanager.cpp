#include "graphicmanager.h"

GraphicManager::GraphicManager()
{
}

bool GraphicManager::init(const char *title, unsigned int x, unsigned int y, unsigned int height, unsigned int width)
{
    if (SDL_InitSubSystem( SDL_INIT_VIDEO ) != 0)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    if(makeWindow(title, x, y, height, width) == false)
    {
        return false;
    }
    initGL(height, width);

    return true;
}

void GraphicManager::freeAll()
{
    destroyWindow();
    SDL_QuitSubSystem(SDL_INIT_VIDEO);
}

void GraphicManager::resetMatrix()
{
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicManager::moveTo(GLfloat x, GLfloat y)
{
    glTranslatef( x, y, 0 );
}

void GraphicManager::scaleViewport(GLfloat xscale, GLfloat yscale)
{
    glScalef( xscale, yscale, 0);
}

void GraphicManager::swapBuffers()
{
    SDL_GL_SwapWindow(_mainWindow);
}

void GraphicManager::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

void GraphicManager::getSize(int *w, int *h)
{
    SDL_GetWindowSize(_mainWindow, w, h);
}

void GraphicManager::setSize(int w, int h)
{
    SDL_SetWindowSize(_mainWindow, w, h);
}

void GraphicManager::resizeViewport()
{
    int w,h;
    getSize(&w, &h);
    glViewport( 0, 0, ( GLsizei )w, ( GLsizei )h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, 0.0, h, 0.0f, 1.0f);
}

void GraphicManager::drawLine(GLfloat xSt, GLfloat ySt, GLfloat xEd, GLfloat yEd, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glBegin(GL_LINES);
        glColor4f(r,g,b,a);

        glVertex2f(xSt, ySt);
        glVertex2f(xEd, yEd);
    glEnd();

    glColor4f(0., 0., 0., 1.0);

    glPopMatrix();
}

void GraphicManager::drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0);

    GLfloat left, bottom, top, right;

    GLfloat size = width/2;
    left = - size;
    right = + size;

    size = height/2;
    top = + size;
    bottom = - size;

    if(filled)
        glBegin(GL_QUADS);
    else
        glBegin(GL_LINE_LOOP);

        glColor4f(r,g,b,a);

        glVertex2f(left, bottom);
        glVertex2f(left, top);
        glVertex2f(right, top);
        glVertex2f(right, bottom);

    glEnd();

    glColor4f(0., 0., 0., 1.0);

    glPopMatrix();
}

void GraphicManager::drawPixel(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glBegin(GL_POINTS);

        glColor4f(r,g,b,a);
        glVertex2f(x, y);

    glEnd();

    glColor4f(0., 0., 0., 1.0);

    glPopMatrix();
}

void GraphicManager::drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glTranslatef(x, y, 0);

    unsigned short N = 50;

    GLfloat verX, verY;
    GLfloat phi = 2*PI/N; //not an angle, but step. Angle is found during ver(tex)X and Y computation

    if(filled)
        glBegin(GL_POLYGON);
    else
        glBegin(GL_LINE_LOOP);

        glColor4f(r,g,b,a);

        for(unsigned short i=0; i<N; i++)
        {
            verX = radius*cos(phi*i);
            verY = radius*sin(phi*i);
            glVertex2f(verX, verY);
        }

    glEnd();

    glColor4f(0., 0., 0., 1.0);

    glPopMatrix();
}

void GraphicManager::drawSprite(Sprite *sp, GLfloat x, GLfloat y, GLfloat scale, GLfloat rotation)
{
    //Push new matrices for this sprite
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glLoadIdentity();
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();


    GLfloat height = sp->getHeight(),
            width  = sp->getWidth ();

    //inits
    initDraw(sp->getTexture());
    setMatrix(x-width/2, y-height/2, width, height, rotation);

    glBegin(GL_QUADS);

        glColor4f(1.0, 1.0, 1.0, 1.0);

        glTexCoord2f (0., 1.);
        glVertex2f (0, height*scale);

        glTexCoord2f (1., 1.);
        glVertex2f (width*scale, height*scale);

        glTexCoord2f (1., 0.);
        glVertex2f (width*scale, 0);

        glTexCoord2f (0., 0.);
        glVertex2f (0, 0);

    glEnd();

    glMatrixMode(GL_MODELVIEW);
    glPopMatrix();
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();

    glColor4f(0., 0., 0., 1.0);

}

void GraphicManager::drawText(GLfloat xSt, GLfloat ySt, std::string text, GLdouble r, GLdouble g, GLdouble b, GLdouble a)
{
    int wW, wH;
    getSize(&wW, &wH);

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    glLoadIdentity();

    if(_font == NULL)
    {
        _font = new FTBufferFont("courier.ttf");
    }


    ///the coorinate should now be relative the box!

    // If something went wrong, bail out.
    if(_font->Error())
    {
        std::cout << "Error during font preparation" << std::endl;
        delete _font;
        return;
    }

    GLfloat top, left;
    top = wH - ySt - 24;
    left = xSt;

    glPushAttrib(GL_ALL_ATTRIB_BITS);
    glDisable(GL_LIGHTING);
    glDisable(GL_DEPTH_TEST);

    glColor4d(r, g, b, a);

    //FTBBox bb;
    // Set the font size and render a small text.
    _font->FaceSize(50);
    //bb = font->BBox(text.c_str());
    //FTBBox ftbb = font->BBox(text.c_str(), -1, FTPoint(left, top));
    _font->Render(text.c_str(), -1, FTPoint(left, top));

    glPopAttrib();
    glPopMatrix();

    //glColor4d(0., 0., 0., 1.);
}

bool GraphicManager::makeWindow(const char *title, const unsigned int x, const unsigned int y, const unsigned int height, const unsigned int width)
{
    _mainWindow = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(_mainWindow == NULL)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    _glcontext = SDL_GL_CreateContext(_mainWindow);
    SDL_GL_MakeCurrent(_mainWindow, _glcontext);

    return true;
}

void GraphicManager::destroyWindow()
{
    //delete font;
    SDL_DestroyWindow(_mainWindow);
    SDL_GL_DeleteContext(_glcontext);
}

void GraphicManager::setMatrix(GLfloat x, GLfloat y, GLfloat width, GLfloat height, float rotation)
{

    glMatrixMode(GL_MODELVIEW);
    glTranslatef(x, y, 0.0f);

    //!Scaling/rotationg not working for now (not needed really).
    //glMatrixMode(GL_TEXTURE);
    if( fabs(rotation)> 1e-5 )
    {
        GLfloat Xc = (width)/2,
                Yc = (height)/2;
        glTranslatef(Xc, Yc, 0.0f);
        glRotatef(rotation, 0.0f, 0.0f, 1.0f);
        glTranslatef(-Xc, -Yc, 0.0f);
    }

//    glScalef(scaleFactor, scaleFactor, 0);
}

void GraphicManager::initDraw(GLuint spr)
{
    if(_currentSprite != spr)
    {
        glBindTexture(GL_TEXTURE_2D, spr);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        _currentSprite = spr;
    }
}

void GraphicManager::initGL(unsigned int h, unsigned int w)
{
    glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);

    glEnable(GL_BLEND);
    glEnable(GL_TEXTURE_2D);

    glShadeModel( GL_SMOOTH );
    glClearColor( 0.9f, 0.9f, 0.9f, 1.f );

    glViewport( 0, 0, ( GLsizei )w, ( GLsizei )h );

    glMatrixMode(GL_TEXTURE);
    glLoadIdentity();

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    glOrtho(0.0, w, 0.0, h, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicManager::freeGL()
{
    //Well, what if?
}

void GraphicManager::initFonts()
{

}

void GraphicManager::freeFonts()
{

}
