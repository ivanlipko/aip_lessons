#include <GL/glut.h>
#include <math.h>

void display() {
    glClear(GL_COLOR_BUFFER_BIT);   ///очистим буфер

    glColor3f(0.0,1.0,0.0); // цвет осей
    glBegin(GL_LINES);      // начнём рисовать первую координатную ось - OX.
    glVertex2f(-550,0);
    glVertex2f(550,0);
    glEnd();

    glBegin(GL_LINES);      // тоже для оси OY
    glVertex2f(0,150);
    glVertex2f(0,-150);
    glEnd();

    glBegin(GL_LINE_STRIP);     // рисуем синусоиду с помощью ломаной линии
    glColor3f(1.0,0.0,0.0);

    for (int i = -500; i <= 500; i++) {
        // вычислим текущую координату Y. Функция Sin() принимает значение в
        // радианах, поэтому i следует умножить на число Пи и разделить на 180.
        // Весь результат умножим на 100, указав тем самым максимальную высоту нашей синусоиды.
        float y = 100 * sin(i*M_PI/180);
        glVertex2d(i,y);
    }
    glEnd();
    glFlush();
}

int main(int argc, char **argv) {
    glutInit(&argc,argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(240,240);
    glutInitWindowPosition(0,0);
    glutCreateWindow("Sin");                                                                                                                                                                    ///создать окно с именем "Sin"
    glClearColor(1.0 , 1.0 , 1.0 , 1.0); // цвет фона окна
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glOrtho(-600.0,600.0,-200.0,200.0,-1.0,1.0);    // Ортогональная координатная сетка
    glutDisplayFunc(display);
    glutMainLoop();  ///передает управление в glut
    return 0;
}
