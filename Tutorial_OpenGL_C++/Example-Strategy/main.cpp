#include <draw.h>
#include <mechanics.h>
#include <GL/glut.h>

static bool ShiftKey = false;
static bool isBuildingMode;
int currentPlayer = 0;

void KeyboardFunc(unsigned char key, int x, int y)
{
    switch (key)
    {
    case 13:
        if(currentPlayer < 1) currentPlayer++;
        else currentPlayer = 0;
        break;
    case 27:
        ShiftKey = true;
        break;

    case 49:
        addObject(0 , x , y , isBuildingMode);
        isBuildingMode = false;
        break;
     case 50:
        addObject(1 , x , y , isBuildingMode);
        isBuildingMode = false;
        break;

    case 51:
        addObject(2 , x , y , isBuildingMode);
        isBuildingMode = false;
        break;

    /* case 52:
        addObject(3 , x , y , isBuildingMode);
        isBuildingMode = false;
        break;
    */
        case 127:
            deleteUnit();
            break;
    }
    if ((key == 232) || (key == 98) || (key == 200) || (key == 66))
    {
        if(isBuildingMode) isBuildingMode = false;
        else isBuildingMode = true;
    }
}

void KeyboardFuncUp(unsigned char key, int x, int y)
{
    switch (key)
    {
        case 27:
            ShiftKey = false;
            break;
    }
}

void MouseFunc(int button, int state, int x, int y)
{
    if(!isBuildingMode && button == GLUT_LEFT_BUTTON && state == GLUT_DOWN)
        mouseLeftButton(x , y , true , ShiftKey);
    if(!isBuildingMode && button == GLUT_LEFT_BUTTON && state == GLUT_UP)
        mouseLeftButton(x , y , false , ShiftKey);
    if(button == GLUT_RIGHT_BUTTON && state == GLUT_DOWN)
        mouseRightButton(x , y);
}

void updateFrame(int)
{
    updateScene();
    glutPostRedisplay();
    glutTimerFunc(10,updateFrame,0);
}

void renderScene()
{
    glClearColor(0.0, 0.0, 0.0, 0.0);
    drawGround();
    drawScene();
    glutSwapBuffers();
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB | GLUT_DEPTH);
    glutInitWindowSize(WINDOW_SIZE , WINDOW_SIZE);
    glutInitWindowPosition(1,1);
    glutCreateWindow("Game");
    glutKeyboardFunc(KeyboardFunc);
    glutKeyboardUpFunc(KeyboardFuncUp);
    glutMouseFunc(MouseFunc);
    glutDisplayFunc(renderScene);
    glutTimerFunc(10,updateFrame,0);
    glutMainLoop();
    return 0;
}
