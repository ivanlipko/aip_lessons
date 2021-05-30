#include "drawlib.h"

void drawCat(Animal c){
    glPushMatrix();
    glTranslatef(c.pos.x,c.pos.y,0);

    glBegin(GL_TRIANGLES);
    glColor3f(.8,.2,.1);
    glVertex2f(-.2,.3);
    glVertex2f( .2,0.3);
    glVertex2f(  0,-.2);

    glColor3f(.1,.8,.1);
    glVertex2f(-.2,.3);
    glVertex2f(-.15,.5);
    glVertex2f(-.1,.3);

    glColor3f(.1,.8,.1);
    glVertex2f(.2,.3);
    glVertex2f(.15,.5);
    glVertex2f(.1,.3);
    glEnd();
    glPopMatrix();
}

void drawQuad(float c, float x){
    glPushMatrix();
    glTranslatef(x,0,0);

    glBegin(GL_QUADS);
    glColor3f(c,0,0);
    glVertex2f(0,0);
    glVertex2f(0,3);
    glVertex2f(3,3);
    glVertex2f(3,0);
    glEnd();

    glPopMatrix();
}
