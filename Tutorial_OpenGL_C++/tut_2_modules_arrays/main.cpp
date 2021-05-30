#include "drawlib.h"

float swanPosX = 0.0;
bool swanMoveRight = true;

bool isDay = true;
unsigned int hour = 0;
float stars[50][2];
float grass[150][2];

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    float angle = 2*M_PI*(float)hour/24;
    drawSky();
    drawStars(stars);
    drawSun(0.75*sin(angle), 0.75*cos(angle), .15*cos(angle)+.05);
    drawLand();
    drawGrass(grass);

    float nightBrighness = 0.15*cos(angle);
    drawForest(nightBrighness);
    glPushMatrix();
    glTranslatef(-.1, -.4, 0);
    drawHome(isDay);
//    glTranslatef(.1, .4, 0);
//    drawSwan(); //original
//    moveSwan(.2*sinf(swanPosX)+0.2); // timer animation
    moveSwan(swanPosX, swanMoveRight); // keyboard move
    glPopMatrix();
    glutSwapBuffers();
}

void animateScene(int value){
//    swanPosX = (swanPosX + .005) * float (swanPosX < .5);
//    swanPosX = (swanPosX + .1);
    glutPostRedisplay();
    glutTimerFunc(33, animateScene, value + 1);
}

void processKeys(unsigned char key, int x, int y){
    if(key == 13)
        exit(0);
    if(key == 110) // n
        isDay = !isDay;
    if(key == 108 || key == 76)  // l or L
        hour = hour + 1;
    if(key == 100){ // d
        swanPosX = swanPosX + 0.1;
        swanMoveRight = true;
    }
    if(key == 97){ // a
        swanPosX = swanPosX - 0.1;
        swanMoveRight = false;
    }
//    glutPostRedisplay(); // Если нет анимации animateScene
}

// подготовка данных
void initDraw(){
    for(unsigned short i=0; i<50; i++)
        for(unsigned short j=0; j<2; j++)
            stars[i][j] = 2*(float) rand()/RAND_MAX - 1.0;
    for(unsigned short i=0; i<150; i++){
        grass[i][0] = 2*(float) rand()/RAND_MAX - 1.0;
        grass[i][1] = (float) rand()/RAND_MAX - 1.0;
    }
}

int main(int argc, char* argv[]){
    initDraw();
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 1, Tree and Home");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
    glutTimerFunc(33, animateScene, 1);  //первый запуск таймера
    glutMainLoop();
    return 0;
}
