#ifndef BUTTONBASE_H
#define BUTTONBASE_H
#include "stdafx.h"

class ButtonBase
{
public:
    ButtonBase();
    void render();

protected:
    //store button top left, width, and height
    bool isPressed;
    float _tpLeftX, _tpLeftY, _width, _height, _vertMargin, _horMargin;
    std::string buttonText;

};

#endif // BUTTONBASE_H
