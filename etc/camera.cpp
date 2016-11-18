#include "camera.h"

Camera::Camera()
{
    _x = _y = 0.;
    _zoom = 1;
    _zoomMin = 0.5;
    _zoomMax = 1.5;
}

void Camera::set(float x, float y)
{
    _x = x;
    _y = y;
}

void Camera::move(float x, float y)
{
    _x += x;
    _y += y;
}

float Camera::getX()
{
    return _x;
}

float Camera::getY()
{
    return _y;
}

void Camera::getXY(float *x, float *y)
{
    *x = _x;
    *y = _y;
}

void Camera::setZoomRange(float min, float max)
{
    _zoomMin = min;
    _zoomMax = max;
}

void Camera::setZoom(float zoom)
{
    if(zoom > _zoomMin && zoom < _zoomMax)
    _zoom = zoom;
}

float Camera::getZoom()
{
    return _zoom;
}
