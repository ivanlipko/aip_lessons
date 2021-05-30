#include <GL/glut.h>
#include <math.h>
#include <iostream>

//float pos_x=0, pos_y=0;
//bool isRight = true;

struct Object{
    float pos_x;
    float pos_y;
    bool isRight;
//    float color[3];
};

Object cat;  // один котик
Object cats[10];  // 10 котиков

const unsigned int pCount = 50;
Object points[pCount];  // pCount точек линии
float angle = 0;

Object points1[pCount];  // pCount точек линии
float angle1 = 0;

void drawCat(Object obj);
void processKeys(unsigned char key, int x, int y);
void renderScene(void);
void tmInitCats(int value);

void animatePoints(Object * points, const unsigned int pCount);
void tmMovePoints(int value);


void initObjects(){
    // инициализация одногокотика
    cat.pos_x = 0;
    cat.pos_y = 0;
    cat.isRight = false;

    // инициализация многих котиков
    for(int i=0; i<10; i++){
        /*
        cats[i].pos_x = 0;  // обращение к элементу массива по индексу i и обращение к элементу структуры через символ точки
        cats[i].pos_y = 0;
        cats[i].isRight = false;
        */

        // инициализация в случайных координатах
        cats[i].pos_x = (float) rand()/RAND_MAX;
        cats[i].pos_y = (float) rand()/RAND_MAX;
        cats[i].isRight = false;
    }

    for(int i=0; i<pCount; i++){
        points[i].pos_x = 0;
        points[i].pos_y = (float) i/pCount;
        points[i].isRight = false;
    }

}

int main(int argc, char* argv[])
{
    initObjects();

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("Lesson - 0, Start");
    glutDisplayFunc(renderScene);
    glutKeyboardFunc(processKeys);
//    glutTimerFunc(1000, tmInitCats, 1);
    glutTimerFunc(50, tmMovePoints, 1);
    glutMainLoop();
    return 0;
}

void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна здесь жить
    glClearColor(1,1,1,1);

//    glColor3f(.8,.2,.1);
//    drawCat(cat);

//    glColor3f(.1,.8,.1);
//    for(int i=0; i<10; i++)
//        drawCat(cats[i]);
    glColor3f(0,0,0);
    animatePoints(points, pCount);

    glColor3f(0,.8,0);
    animatePoints(points1, pCount);

    // эта функция должна здесь жить
    glutSwapBuffers();
}

void drawCat(Object obj){
    // рисуем треугольник
    glPushMatrix();
    glTranslatef(obj.pos_x,obj.pos_y,0);
    glRotatef(90,0,0,1);

    if(obj.isRight)
        glRotatef(180,0,0,1);

    glBegin(GL_TRIANGLES);
    glVertex2f(-.2,-.3);
    glVertex2f( .2,-0.3);
    glVertex2f(  0,.2);
    glEnd();
    glPopMatrix();
}

void processKeys(unsigned char key, int x, int y){
    if(key == 100 || key == 68){ // d or D
        cat.pos_x = cat.pos_x + 0.1;
        cat.isRight = true;
    }
    if(key == 97){ // a
        cat.pos_x = cat.pos_x - 0.1;
        cat.isRight = false;
    }

    if(key == 13)
        exit(0); // close app

    glutPostRedisplay(); // Если нет анимации animateScene
}

void animatePoints(Object * points, const unsigned int pCount){
    glPointSize(5);
    glEnable(GL_POINT_SMOOTH);

    glBegin(GL_POINTS);
//    glColor3f(1-sin(3.14*(float)((int)angle % 360)/360)*.5+.2,0,0);
    glVertex2f(0,0);
    for(int i=0; i<pCount; i++){
        glVertex2f( points[i].pos_x, points[i].pos_y);
    }
    glEnd();

    glBegin(GL_LINE_STRIP);
    glVertex2f(0,0);
    for(int i=0; i<pCount; i++){
        glVertex2f( points[i].pos_x, points[i].pos_y);
    }
    glEnd();
}


void tmInitCats(int value){
    // ставим коитков в случайных координатах
    for(int i=0; i<10; i++){
        cats[i].pos_x = (float) 2*rand()/RAND_MAX-1;
        cats[i].pos_y = (float) 2*rand()/RAND_MAX-1;
        cats[i].isRight = false;
    }

    glutPostRedisplay();  // перерисовываем экран
    glutTimerFunc(1000,tmInitCats,1);  //запускаем таймер заново.
}

void tmMovePoints(int value){
    angle += 4.0;
    if (angle >= pCount*360)
        angle = 0;
    for(int i=0; i<pCount; i++){
        points[i].pos_x = (float) i/pCount * cos((float) i/pCount * angle * 3.14 / 180.0);
        points[i].pos_y = (float) i/pCount * sin((float) i/pCount * angle * 3.14 / 180.0);
    }

//    angle1 += 2.0;
    angle1 -= 4.0;
    if (angle1 >= pCount*360)
        angle1 = 0;
    for(int i=0; i<pCount; i++){
        points1[i].pos_x = (float) i/pCount * cos((float) i/pCount * angle1 * 3.14 / 180.0);
        points1[i].pos_y = (float) i/pCount * sin((float) i/pCount * angle1 * 3.14 / 180.0);
    }


    glutPostRedisplay();  // перерисовываем экран
    glutTimerFunc(33,tmMovePoints,1);  //запускаем таймер заново.
}


// идеи брать здесь http://quil.info/sketches/
