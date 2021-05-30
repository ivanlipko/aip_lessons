#include <stdlib.h>
#include <GL/glut.h>
#include <math.h>
#include <draw.h>
#include <mechanics.h>


void drawGround(){
    //почва
    glBegin(GL_QUADS);
    glColor3d(.4, .7, .5);
    glVertex2d(-1 ,-1);
    glVertex2d(-1 , 1);
    glVertex2d(1 ,  1);
    glVertex2d(1 , -1);
    glEnd();
}

void drawUnit(double unitPosX, double unitPosY, double red, double green, double blue, int id , int HP){
    glPushMatrix();
    glTranslated(unitPosX, unitPosY, 0);
    glBegin(GL_QUADS);
    glColor3d(red, green, blue);
    glVertex2d(.05 , .05);
    glVertex2d(.05 , -.05);
    glVertex2d(-.05 , -.05);
    glVertex2d(-.05 , .05);
    glColor3d(.5, 1, .7);
    glVertex2d(-.05 , -.055);
    glVertex2d(-.05 + (double)HP / 1000 , -.055);
    glVertex2d(-.05 + (double)HP / 1000 , -.057);
    glVertex2d(-.05 , -.057);
    glEnd();
    glColor3d(1, 1, 1);
    glLineWidth(1);
    glScaled(.5 , .5 , 1);
    switch (id)
    {
    case 0:
        glBegin(GL_LINES);
        glVertex2d(.07 , .03);
        glVertex2d(-.07 , -.03);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3d(0, 0, 0);
        glVertex2d(.05 , .03);
        glVertex2d(.076 , .033);
        glVertex2d(.055 , .015);
        glColor3d(1, 1, 1);
        glVertex2d(-.06 , -.025);
        glVertex2d(-.09 , -.03);
        glVertex2d(-.085 , -.045);
        glEnd();
        break;
    case 1:
        glBegin(GL_TRIANGLES);
        glVertex2d(-.07 , -.02);
        glVertex2d(-.04 , -.04);
        glVertex2d(.08 , .08);
        glEnd();
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex2d(-.055 , -.03);
        glVertex2d(-.08 , -.055);
        glEnd();
        break;
    case 2:
        glBegin(GL_TRIANGLES);
        glVertex2d(.08 , -.07);
        glVertex2d(-.01 , -.07);
        glVertex2d(-.03 , .08);
        glVertex2d(-.03 , .08);
        glVertex2d(-.00 , -.00);
        glVertex2d(-.09 , -.04);
        glEnd();
        glPointSize(3);
        glColor3d(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2d(-.03 , .04);
        glEnd();
    }
    glPopMatrix();
}

void drawBuilding(double unitPosX, double unitPosY, int progress, double red, double green, double blue, int id, int HP){
    glPushMatrix();
    glTranslated(unitPosX, unitPosY, 0);
    glBegin(GL_QUADS);
    glColor3d(red, green, blue);
    glVertex2d(.1 , .1);
    glVertex2d(.1 , -.1);
    glVertex2d(-.1 , -.1);
    glVertex2d(-.1 , .1);
    glColor3d(.5, 1, .7);
    glVertex2d(-.08 , -.1);
    glVertex2d(-.08 + (double)HP / 6500 , -.1);
    glVertex2d(-.08 + (double)HP / 6500 , -.103);
    glVertex2d(-.08 , -.103);
    glEnd();

    glLineWidth(2);
    glColor3d(1, 1, 1);
    switch (id)
    {
    case 0:
        glBegin(GL_LINES);
        glVertex2d(.07 , .03);
        glVertex2d(-.07 , -.03);
        glEnd();
        glBegin(GL_TRIANGLES);
        glColor3d(0, 0, 0);
        glVertex2d(.05 , .03);
        glVertex2d(.075 , .032);
        glVertex2d(.055 , .015);
        glColor3d(1, 1, 1);
        glVertex2d(-.06 , -.025);
        glVertex2d(-.09 , -.03);
        glVertex2d(-.085 , -.045);
        glEnd();
        break;
    case 1:
        glBegin(GL_TRIANGLES);
        glVertex2d(-.07 , -.02);
        glVertex2d(-.04 , -.04);
        glVertex2d(.08 , .08);
        glEnd();
        glLineWidth(5);
        glBegin(GL_LINES);
        glVertex2d(-.055 , -.03);
        glVertex2d(-.08 , -.055);
        glEnd();
        break;
    case 2:
        glBegin(GL_TRIANGLES);
        glVertex2d(.08 , -.07);
        glVertex2d(-.01 , -.07);
        glVertex2d(-.03 , .08);
        glVertex2d(-.03 , .08);
        glVertex2d(-.00 , -.00);
        glVertex2d(-.09 , -.04);
        glEnd();
        glPointSize(3);
        glColor3d(0, 0, 0);
        glBegin(GL_POINTS);
        glVertex2d(-.03 , .04);
        glEnd();
    }

    if (progress > 0)
    {
        glBegin(GL_QUADS);
        glColor3d(0, 0, 0);
        glVertex2d( - .08 , - .08);
        glVertex2d( - .08 , - .06);
        glVertex2d( - .08 + (double)progress / 700 , - .06);
        glVertex2d( - .08 + (double)progress / 700 , - .08);
        glEnd();
    }

    glPopMatrix();
}

void drawBeacon(double pointX, double pointY){
    glPointSize(10);
    glBegin(GL_POINTS);
    glColor3d(0,0,0);
    glVertex2d(pointX , pointY);
    glEnd();
}

void drawFrame(double pointX , double pointY)
{
    glLineWidth(2);
    glBegin(GL_LINES);
    glVertex2d(pointX , pointY);
    glVertex2d(pointX , pointY);
    glEnd();
}

void drawScene()
{
    for(int i = 0; i < structCount; i++)  //Рисование построек
    {
        switch (buildings[i].player)
        {
            case 0: Color.r = 0.9 ; Color.g = 0.2 ; Color.b = 0.2; break;
            case 1: Color.r = 0.2 ; Color.g = 0.2 ; Color.b = 0.9; break;
        }
        if (buildings[i].isActive)
        {
            Color.r = Color.r + .2;
            Color.g = Color.g + .2;
            Color.b = Color.b + .2;
            drawBeacon(buildings[i].rallyPointX , buildings[i].rallyPointY);
        }
            drawBuilding(buildings[i].x,buildings[i].y, buildings[i].progress , Color.r,Color.g,Color.b , buildings[i].id , buildings[i].hitPoints);
    }
    for(int i = 0; i < unitCount; i++)  //Рисование юнитов
    {
        switch (units[i].player)
        {
            case 0: Color.r = 0.9 ; Color.g = 0.2 ; Color.b = 0.2; break;
            case 1: Color.r = 0.2 ; Color.g = 0.2 ; Color.b = 0.9; break;
        }
        if (units[i].isActive)
        {
            Color.r = Color.r + .2;
            Color.g = Color.g + .2;
            Color.b = Color.b + .2;
        }
        drawUnit(units[i].x , units[i].y , Color.r,Color.g,Color.b , units[i].id , units[i].hitPoints);
    }
}


