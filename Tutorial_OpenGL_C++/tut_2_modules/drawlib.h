#ifndef DRAWLIB_H
#define DRAWLIB_H

#include <GL/glut.h>
struct Pos{
    float x;
    float y;
};

struct Animal{
    Pos pos;
    bool isRight;
};

void drawCat(Animal c);
void drawQuad(float c, float x);

#endif // DRAWLIB_H
