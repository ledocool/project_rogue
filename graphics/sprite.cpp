#include "sprite.h"

sprite::sprite()
{
    height = 0;
    width = 0;
    texture = 0;
    name = "";
}

sprite::sprite(const char *filename)
{
    if(load(filename) == false)
        throw SDL_GetError();
}

sprite::~sprite()
{
    kill();
}

bool sprite::load(const char *filename)
{
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *surf = IMG_Load(filename);

    if(surf == NULL)
    {
        std::cout << "Failed loading texture: " << SDL_GetError() << std::endl;
        IMG_Quit();
        return false;
    }

    height = surf->h;
    width = surf->w;

    name = filename;

    glGenTextures(1, &texture); //gen tex id
    glBindTexture(GL_TEXTURE_2D, texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //Beauty grafon

    if(surf->format->Amask)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width, height, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
    else
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, width, height, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);

    SDL_FreeSurface(surf);
    IMG_Quit();

    //singleton<spriteManager>::get()->regSprite(this);
    return true;
}

GLuint sprite::getTexture()
{
    return texture;
}

GLuint sprite::getHeight()
{
    return height;
}

GLuint sprite::getWidth()
{
    return width;
}

void sprite::kill()
{
    glDeleteTextures(1, &texture);
}
