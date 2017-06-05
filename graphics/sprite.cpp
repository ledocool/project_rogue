#include "sprite.h"

Sprite::Sprite()
{
    _height = 0;
    _width = 0;
    _texture = 0;
    _name = "";
}

Sprite::Sprite(const char *filename)
{
    if(load(filename) == false)
        throw SDL_GetError();
}

Sprite::~Sprite()
{
    kill();
}

bool Sprite::load(const char *filename)
{
    IMG_Init( IMG_INIT_PNG );
    SDL_Surface *surf = IMG_Load(filename);

    if(surf == NULL)
    {
        std::cout << "Failed loading texture: " << SDL_GetError() << std::endl;
        IMG_Quit();
        return false;
    }

    _height = surf->h;
    _width = surf->w;

    _name = filename;

    glGenTextures(1, &_texture); //gen tex id
    glBindTexture(GL_TEXTURE_2D, _texture);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_CLAMP_TO_EDGE);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_CLAMP_TO_EDGE);

    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_NEAREST);
    glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_NEAREST); //Beauty grafon

    if(surf->format->Amask)
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, _width, _height, 0, GL_RGBA, GL_UNSIGNED_BYTE, surf->pixels);
    else
        glTexImage2D(GL_TEXTURE_2D, 0, GL_RGB, _width, _height, 0, GL_RGB, GL_UNSIGNED_BYTE, surf->pixels);

    SDL_FreeSurface(surf);
    IMG_Quit();

    //singleton<spriteManager>::get()->regSprite(this);
    return true;
}

GLuint Sprite::getTexture()
{
    return _texture;
}

GLuint Sprite::getHeight()
{
    return _height;
}

GLuint Sprite::getWidth()
{
    return _width;
}

void Sprite::kill()
{
    glDeleteTextures(1, &_texture);
}
