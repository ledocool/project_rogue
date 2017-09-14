#ifndef SPRITE_H
#define SPRITE_H

#include "stdafx.h"
#include "etc/singleton.h"
#include "graphics/spritemanager.h"

class Sprite
{
friend class graphicsManager;
public:
    Sprite();
    Sprite(const char *filename);
    ~Sprite();

    bool load(const char *filename);

    GLuint getTexture();
    GLuint getHeight();
    GLuint getWidth();

private:
    void kill(); //deletes sprite

    GLuint _texture;
    GLuint _height, _width;
    std::string _name;

};
#endif // SPRITE_H
