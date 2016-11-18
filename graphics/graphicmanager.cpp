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
    //readyfont();
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
    SDL_GL_SwapWindow(mainWindow);
}

void GraphicManager::clear()
{
    glClear(GL_COLOR_BUFFER_BIT);
}

//void GraphicManager::readyfont()
//{
////    TTF_Font *baseFnt = NULL;
////    baseFnt = TTF_OpenFont("courier.ttf", 24);
////    std::cout << TTF_GetError() << std::endl;
////    SDL_Color black;
////    black.r = 0; black.b = 0; black.g = 0; black.a = 0;
////    SDL_Surface *surf = TTF_RenderUTF8_Solid(baseFnt, "Hello world", black);
////    //SDL_PixelFormat *fmt = surf->format;
////    //fmt->format = SDL_PIXELFORMAT_RGB888;
////    //SDL_Surface *surf2 = SDL_ConvertSurface(surf, fmt, 0);
////    //SDL_FreeSurface(surf);
////    //surf = surf2;

////    if(surf == NULL)
////    {
////        std::cout << "Failed loading texture: " << SDL_GetError() << std::endl;
////        IMG_Quit();
////        return;
////    }

////    GLuint texture;

////    GLfloat h, w;

////    h = surf->h;
////    w = surf->w;
////    glGenTextures(1, &texture); //gen tex id
////    glBindTexture(GL_TEXTURE_2D, texture);

////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
////    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //Beauty grafon

////    if(surf->format->Amask)
////        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
////    else
////        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, w, h, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);

////    GLfloat height = surf->h,//fabs(yEd - ySt),
////            width  = surf->w;//fabs(xEd - xSt);

////    std::vector<int> ii;
////    ii.resize(surf->h * surf->w);

////    for(int i=0; i<surf->h * surf->w; i++)
////    {
////        ii[i] = *(int *)(surf->pixels + i);
////    }

////    //int ioi = SDL_PIXELFORMAT_BGR24;

////    SDL_FreeSurface(surf);
////    TTF_CloseFont(baseFnt);
////    font = texture;
//}

void GraphicManager::getSize(int *w, int *h)
{
    SDL_GetWindowSize(mainWindow, w, h);
}

void GraphicManager::setSize(int w, int h)
{
    SDL_SetWindowSize(mainWindow, w, h);
}

void GraphicManager::resizeViewport()
{
    int w,h;
    getSize(&w, &h);
    glViewport( 0, 0, ( GLsizei )w, ( GLsizei )h );
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(0.0, w, h, 0.0, 0.0f, 1.0f);
}

void GraphicManager::drawLine(GLfloat xSt, GLfloat ySt, GLfloat xEd, GLfloat yEd, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();

    glBegin(GL_LINES);
        glColor4f(r,g,b,a);

        glVertex2f(xSt, ySt);
        glVertex2f(xEd, yEd);
    glEnd();

    glColor4f(0., 0., 0., 1.0);

    //glPopMatrix();
}

void GraphicManager::drawRect(GLfloat x, GLfloat y, GLfloat width, GLfloat height, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled)
{
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();
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

    //glPopMatrix();
}

void GraphicManager::drawPixel(GLfloat x, GLfloat y, GLfloat r, GLfloat g, GLfloat b, GLfloat a)
{
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();

    glBegin(GL_POINTS);

        glColor4f(r,g,b,a);
        glVertex2f(x, y);

    glEnd();

    glColor4f(0., 0., 0., 1.0);

    //glPopMatrix();
}

void GraphicManager::drawCircle(GLfloat x, GLfloat y, GLfloat radius, GLfloat r, GLfloat g, GLfloat b, GLfloat a, bool filled)
{
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();
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

    //glPopMatrix();
}

void GraphicManager::drawSprite(sprite *sp, GLfloat x, GLfloat y, GLfloat scale, GLfloat rotation)
{
    //Push new matrices for this sprite
    glMatrixMode(GL_TEXTURE);
    glPushMatrix();
    glLoadIdentity();
    //glMatrixMode(GL_MODELVIEW);
    //glPushMatrix();


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

    //glMatrixMode(GL_MODELVIEW);
    //glPopMatrix();
    glMatrixMode(GL_TEXTURE);
    glPopMatrix();

    glColor4f(0., 0., 0., 1.0);

}

void GraphicManager::drawText(GLfloat xSt, GLfloat ySt, GLfloat xEd, GLfloat yEd, std::string text)
{
    FTGLPixmapFont font("courier.ttf");
    // If something went wrong, bail out.
    if(font.Error())
        std::cout << "Error during font preparation" << std::endl;

    // Set the font size and render a small text.
    font.FaceSize(24);
    font.Render(text.c_str(), -1, FTPoint(xSt, ySt));
}

bool GraphicManager::makeWindow(const char *title, unsigned int x, unsigned int y, unsigned int height, unsigned int width)
{
    mainWindow = SDL_CreateWindow(title, x, y, width, height, SDL_WINDOW_OPENGL | SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);

    if(mainWindow == NULL)
    {
        std::cout << "SDL_Init Error: " << SDL_GetError() << std::endl;
        return false;
    }

    glcontext = SDL_GL_CreateContext(mainWindow);
    SDL_GL_MakeCurrent(mainWindow, glcontext);

    return true;
}

void GraphicManager::destroyWindow()
{
    //delete font;
    SDL_DestroyWindow(mainWindow);
    SDL_GL_DeleteContext(glcontext);
}

void GraphicManager::setMatrix(GLfloat x, GLfloat y, GLfloat width, GLfloat height, float rotation)
{

    glMatrixMode(GL_MODELVIEW);
    glTranslatef(x, y, 0.0f);

    //!Scaling/rotationg aint working for now (aint needed really).
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
    if(currentSprite != spr)
    {
        glBindTexture(GL_TEXTURE_2D, spr);
        glTexEnvf(GL_TEXTURE_ENV, GL_TEXTURE_ENV_MODE, GL_MODULATE);
        currentSprite = spr;
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

    glOrtho(0.0, w, h, 0.0, 0.0f, 1.0f);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

void GraphicManager::freeGL()
{
    //Well, what if?
}
