#ifndef COLOR_H
#define COLOR_H


struct Color
{
public:
    Color();
    Color(float r, float g, float b)
    {
        this->r = r;
        this->g = g;
        this->b = b;
    }

    float r, g, b;
};

#endif // COLOR_H
