#include <GL/glut.h>

// блок объявлений функций
void renderScene(void);

// блок реализации функций

int main(int argc, char* argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100,100);
    glutInitWindowSize(600,600);
    glutCreateWindow("OpenGL Start Application");
    glutDisplayFunc(renderScene);
    glutMainLoop();
    return 0;
}


void renderScene(void) {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); // эта функция должна быть первой в renderScene

	glBegin(GL_TRIANGLES);
	glColor3f(.9, 0, 0);
	glVertex2f(-0.5, -0.5);
	glVertex2f(0.0, 0.5);
	glVertex2f(0.5, -0.5);
	
	// 0. добавить
     glEnd();
	
	// 1. изменить параметры функций glVertex2f
	// обратить внимание на то, что мы ЧТО-ТО изменяем в коде и это отражается в том, что мы видим

	// 2. Добавить характеристику вершины - её цвет
	// glColor3f, RGB, 0..1

	// 3. Добавить ещё один треугольник

	// 4. Рисуем морду кота

    glutSwapBuffers(); // эта функция должна быть последний в renderScene
}
