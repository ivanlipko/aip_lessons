#include <GL/glut.h>

void drawCat(float x = 0, float y = 0);
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

    glPushMatrix();
    drawCat();
    drawCat(.4,.4);
    drawCat(.4,0);
    glPopMatrix();

    glutSwapBuffers();
    return;
}

void drawCat(float x, float y){
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
}
