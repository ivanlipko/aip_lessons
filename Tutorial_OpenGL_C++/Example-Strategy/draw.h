#ifndef DRAW_H
#define DRAW_H

#define MAX_UNITS_COUNT 100
#define WINDOW_SIZE 1000

void drawScene();
void drawGround();
void drawUnit(double unitPosX = 0.0 , double unitPosY = 0.0, double red = 0.0, double green = 0.0, double blue = 0.0 , int id = 0 , int HP = 100);
void drawBuilding(double unitPosX = 0.0, double unitPosY = 0.0, int progress = 0 , double red = 0.0, double green = 0.0, double blue = 0.0 , int id = 0 , int HP = 1000);
void drawBeacon(double pointX=0.0, double pointY=0.0);
void drawFrame(double pointX = 0.0 , double pointY = 0.0);
#endif // DRAW_H
