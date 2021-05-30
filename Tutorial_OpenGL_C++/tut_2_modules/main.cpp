//#include <GL/glut.h>
#include "drawlib.h"

void renderScene();
void processKeys(unsigned char key, int x, int y);

Animal cat = {0,0,false};
Animal catVasya = {catVasya.isRight = false,
                catVasya.pos.x=0,
                catVasya.pos.y=0};

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Modules");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutMainLoop();
    return 0;
}

void processKeys(unsigned char key, int x, int y){
    if(key == 13)
        exit(0);
    if(key == 110) // n
        cat.pos.x += .1;
    if(key == 97) // a
        cat.pos.x -= .1;

    glutPostRedisplay(); // Если нет анимации animateScene
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    drawCat(cat);

    /*
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
    */
    /*
    // мордочки
    glPushMatrix();
    glTranslatef(-1,0,0);
    for(int i=0; i<5; i++)
        drawCat((float)i/2);
    glPopMatrix();
    */

    glutSwapBuffers();
    return;
}
