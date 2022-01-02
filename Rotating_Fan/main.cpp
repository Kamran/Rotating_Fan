#include<windows.h>
#include <GL/glut.h>
#include <stdlib.h>
#include <math.h>

using namespace std;

static GLfloat spin = 0.0;

void displayFan(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    glPushMatrix();

    glColor3f(0.0, 1.0, 0.0);

    glRectf(-20.0, -4.0, 20.0, 4.0);
    glRectf(-4.0, -20.0, 4.0, 20.0);
    glColor3f(1.0, 1.0, 1.0);
    glutSolidTorus(1.00, 5.4, 10, 100);
    glPopMatrix();

    glFlush();
}


void init(void)
{
    glClearColor (1.0, 0.0, 0.0, 0.0);
    glOrtho(-50.0, 50.0, -50.0, 50.0, -1.0, 1.0);
}

void spinRotation_right(void)
{
    spin = -.60;
    glutPostRedisplay();
    glRotatef(spin, 0.0, 0.0, 1.0);
}


int i=0;
void input_key(unsigned char key, int x, int y)
{

    switch (key)
    {

    case 's':
    {
        if(i==0)
        {
            glutIdleFunc(spinRotation_right);
            i=1;
        }

        else
        {
            glutIdleFunc(NULL);
            i=0;
        }
    }

    case '+':
    {
        glRotatef(-10, 0.0, 0.0, 1.0);
        break;
    }

    case '-':
        glRotatef(3, 0.0, 0.0, 1.0);
        break;

    default:
        break;
    }
}


int main(int argc, char** argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize (250, 250);
    glutInitWindowPosition (100, 100);
    glutCreateWindow ("Rotation of a FAN");
    init();

    glutDisplayFunc(displayFan);
    glutKeyboardFunc(input_key);

    glutMainLoop();
    return 0;
}
