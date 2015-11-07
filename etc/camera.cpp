#include "camera.h"

camera::camera()
{
    _x = _y = 0.;
    _zoom = 1;
    _zoomMin = 0.5;
    _zoomMax = 1.5;
}

void camera::set(float x, float y)
{
    _x = x;
    _y = y;
}

void camera::move(float x, float y)
{
    _x += x;
    _y += y;
}

float camera::getX()
{
    return _x;
}

float camera::getY()
{
    return _y;
}

void camera::getXY(float *x, float *y)
{
    *x = _x;
    *y = _y;
}

void camera::setZoomRange(float min, float max)
{
    _zoomMin = min;
    _zoomMax = max;
}

void camera::setZoom(float zoom)
{
    if(zoom > _zoomMin && zoom < _zoomMax)
    _zoom = zoom;
}

float camera::getZoom()
{
    return _zoom;
}
