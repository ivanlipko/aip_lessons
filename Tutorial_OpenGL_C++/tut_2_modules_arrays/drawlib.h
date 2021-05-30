#ifndef DRAWLIB_H
#define DRAWLIB_H

#include <GL/glut.h>
#include <math.h>

void drawFir(float brightness = 0.0);
void drawSwan();
void drawHome(bool isLightOn = true);
void drawSun(float cX = 0.0, float cY = 0.0, float radius = 1.0);
void drawSky();
void drawLand();
void moveSwan(float x, bool direction);
void drawForest(float nightBrighness);
void drawStars(float points[20][2]);
void drawGrass(float points[150][2]);

#endif // DRAWLIB_H
