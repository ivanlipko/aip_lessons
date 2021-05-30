#include <GL/glut.h>

void drawCat(float x = 0, float y = 0);
void drawQuad(float c, float x);
void renderScene();

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 0, Start");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    // красные полоски
    glPushMatrix();
    glTranslatef(-1,0,0);
    glScalef(.2,2,0);
    float pos = 0;
    float color = .1;
    for(int i=0; i<5; i++){
        drawQuad(color, pos);
        pos = pos + 2;
        color = color + .2;
    }
    glPopMatrix();

    // мордочки
    glPushMatrix();
    glTranslatef(-1,0,0);
    for(int i=0; i<5; i++)
        drawCat((float)i/2);
    glPopMatrix();

    glutSwapBuffers();
    return;
}

void drawCat(float x, float y){
    glPushMatrix();
    glTranslatef(x,y,0);

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
