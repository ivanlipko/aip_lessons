#ifndef DRAWLIB_H
#define DRAWLIB_H

#include <GL/glut.h>
#undef __STRICT_ANSI__ // to use  M_PI constant
//#define _USE_MATH_DEFINES
#include <math.h>

void drawFir(float brightness = 0.0);
void drawSwan();
void drawHome(bool isLightOn = true);
void drawSun(float cX = 0.0, float cY = 0.0, float radius = 1.0);
void drawSky();
void drawLand();
void moveSwan(float x, bool direction);

#endif // DRAWLIB_H



/*
//your .h file
#ifndef DRAWLIB_H
#define DRAWLIB_H
 // your code here
#endif // DRAWLIB_H
*/
