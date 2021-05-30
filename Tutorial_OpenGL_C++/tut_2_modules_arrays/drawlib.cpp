#include "drawlib.h"

void drawFir(float brightness){
    glBegin(GL_TRIANGLES);
    // пенёк
    glColor3f(.7+brightness, .6+brightness, .1+brightness);
    glVertex2f(-0.05, 0.29);
    glVertex2f(0.05, 0.29);
    glVertex2f(0.05, 0.25);
    glVertex2f(0.05, 0.25);
    glVertex2f(-0.05, 0.25);
    glVertex2f(-0.05, 0.29);
    // ярус 2
    glColor3f(.1+brightness, .7+brightness, .1+brightness);
    glVertex2f(-0.14, 0.29);
    glVertex2f(0.0, 0.38);
    glVertex2f(0.14, 0.29);
    // ярус 1
    glColor3f(.1+brightness, .8+brightness, .1+brightness);
    glVertex2f(-0.13, 0.36);
    glVertex2f(0.0, 0.45);
    glVertex2f(0.13, 0.36);
    // верхушка
    glColor3f(.1f+brightness, .9f+brightness, .1f+brightness);
    glVertex2f(-0.1f, 0.43f);
    glVertex2f(0.0f, 0.5f);
    glVertex2f(0.1f, 0.43f);
    glEnd();
}

void drawSwan(){
    glTranslatef(-.15,0,0);
    // герой
    glBegin(GL_POLYGON);
    // тело
    glColor3f(.51f, .51f, .62f);
    glVertex2f(0.03f, 0.0f);
    glVertex2f(0.0f, 0.09f);
    glVertex2f(0.06f, 0.12f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.18f, 0.07f);
    glVertex2f(0.16f, 0.0f);
    glEnd();
    // шея и голова
    glBegin(GL_TRIANGLES);
    glColor3f(.7f, .1f, .2f);
    glVertex2f(0.18f, 0.07f);
    glVertex2f(0.15f, 0.1f);
    glVertex2f(0.14f, 0.2f);

    glVertex2f(0.14f, 0.2f);
    glVertex2f(0.16f, 0.21f);
    glVertex2f(0.18f, 0.07f);

    glVertex2f(0.16f, 0.21f);
    glVertex2f(0.21f, 0.19f);
    glVertex2f(0.165f, 0.17f);
    glEnd();
}

void drawHome(bool isLightOn){
    glBegin(GL_QUADS);
    // стены
    glColor3f(.91f, .1f, .91f);
    glVertex2f(0.4f, 0.0f);
    glVertex2f(0.4f, 0.3f);
    glVertex2f(0.7f, 0.3f);
    glVertex2f(0.7f, 0.0f);
    // окно
    if(isLightOn)
        glColor3f(.1f, .71f, .91f);
    else
        glColor3f(.6f, .2f, .31f);
    glVertex2f(0.45f, 0.17f);
    glVertex2f(0.45f, 0.25f);
    glVertex2f(0.53f, 0.25f);
    glVertex2f(0.53f, 0.17f);
    // дверь
    glColor3f(.81f, .03f, .81f);
    glVertex2f(0.55f, 0.0f);
    glVertex2f(0.55f, 0.22f);
    glVertex2f(0.67f, 0.22f);
    glVertex2f(0.67f, 0.0f);
    glEnd();

    glBegin(GL_TRIANGLES);
    // крыша
    glColor3f(.61f, .1f, .2f);
    glVertex2f(0.37f, 0.3f);
    glVertex2f(0.6f, 0.52f);
    glVertex2f(0.73f, 0.3f);
    glEnd();
}


void drawSun(float cX, float cY, float radius){
    glBegin(GL_TRIANGLE_FAN);
    glColor3f(.90, .1, .07);
    glVertex2f(cX, cY);
    glColor3f(.95, .72, .07);
    //    for(float angle = 0.0; angle <= 2*M_PI+.3; angle = angle + .3)
    //        glVertex2f(cX+radius*sinf(angle), cY+radius*cosf(angle));
    float angle = 0.0;
    while(angle <= 2*M_PI+.3){
        glVertex2f(cX+radius*sinf(angle), cY+radius*cosf(angle));
        angle = angle + .3;
    }
    glEnd();

    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.9,0.72,.07);
    angle = 0.0;
    while(angle <= 2*M_PI+.3){
        for(unsigned short i=0; i<25; i++)
            glVertex2f(cX+radius*sinf(angle) + 0.05*(float) rand()/RAND_MAX - .025,
                       cY+radius*cosf(angle) + 0.05*(float) rand()/RAND_MAX - .025);
        angle = angle + .3;
    }


    glEnd();
}

void drawSky(){
    glBegin(GL_QUADS);
    glColor3f(.21, .32, .7);
    glVertex2f(-1, 1);
    glVertex2f(1, 1);
    glColor3f(.31, .32, .97);
    glVertex2f(1, 0);
    glVertex2f(-1, 0);
    glEnd();
}

void drawLand(){
    glBegin(GL_QUADS);
    glColor3f(.0, .32, .07);
    glVertex2f(-1, -1);
    glColor3f(.05, .42, .05);
    glVertex2f(-1, 0);
    glVertex2f(1, 0);
    glColor3f(.05, .32, .05);
    glVertex2f(1, -1);
    glEnd();
}

void moveSwan(float x, bool direction){
    glPushMatrix();
    glTranslatef(x, 0, 0);
    if(!direction) {
        glPushMatrix();
        glRotatef(180,0,1,0);
    }
    drawSwan();
    if(!direction) {
        glPopMatrix();
    }
    glPopMatrix();
}

void drawForest(float nightBrighness){
    glPushMatrix();
    // ряд ёлочек
    glScalef(.8, .8, 1);
    glTranslatef(-1.2, -0.3, 0);
    for(int i=0; i<9; i++) {
        drawFir(-.21+nightBrighness-.2);
        glTranslatef(.3, 0, 0);
    }
    glTranslatef(-.3*9-.2, -.15, 0);
    glScalef(1.2, 1.2, 1);
    for(int i=0; i<9; i++) {
        drawFir(-.11+nightBrighness-.2);
        glTranslatef(.27, 0, 0);
    }
    glTranslatef(-.27*9, -.15, 0);
    glScalef(1.1, 1.1, 1);
    for(int i=0; i<9; i++) {
        drawFir(-.01+nightBrighness-.2);
        glTranslatef(.27, 0, 0);
    }
    glPopMatrix();
}

void drawStars(float points[50][2]){
    glPointSize(1);
    glBegin(GL_POINTS);
    glColor3f(1,1,1);
    for(unsigned short i=0; i<50; i++)
        glVertex2fv(points[i]);
    glEnd();
}

void drawGrass(float points[150][2]){
    glPointSize(25);
    glBegin(GL_POINTS);
    glColor3f(0.05,0.38,.02);
    for(unsigned short i=0; i<150; i++)
        glVertex2fv(points[i]);
    glEnd();
}
/*
void drawSunwork(){
    glPointSize(5);
    glBegin(GL_POINTS);
    glColor3f(0.05,0.38,.02);
    for(unsigned short i=0; i<150; i++)
        glVertex2f((float) rand()/RAND_MAX - 1.0, (float) rand()/RAND_MAX - 1.0);
    glEnd();
}
*/
