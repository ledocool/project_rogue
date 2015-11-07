#ifndef CAMERA_H
#define CAMERA_H

class camera
{
public:
    camera();

    void set(float x, float y);
    void move(float x, float y);


    float getX();
    float getY();
    void getXY(float *x, float *y);

    void setZoomRange(float min, float max);
    void setZoom(float zoom);
    float getZoom();

private:
    float _x, _y;
    float _zoom, _zoomMin, _zoomMax;
};

#endif // CAMERA_H
