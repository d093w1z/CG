#include<GL/glut.h>
// #include<stdlib.h>
#include<iostream>
using namespace std;
float x1, x2, y1, y2;

void keyboardHandler(unsigned char c, int x, int y) {
    switch (c)
    {
    case '\e':
        cout<< "Quitting!"<<endl;
        exit(0);
        break;

    default:
        break;
    }
}

void display(void)
{
    float dy, dx, step, x, y, k, Xin, Yin;
    dx = x2 - x1;
    dy = y2 - y1;

    if (abs(dx) > abs(dy))
    {
        step = abs(dx);
    }
    else
        step = abs(dy);

    Xin = dx / step;
    Yin = dy / step;

    x = x1;
    y = y1;
    glBegin(GL_POINTS);
    glVertex2i(x, y);
    glEnd();

    for (k = 1;k <= step;k++)
    {
        x = x + Xin;
        y = y + Yin;

        glBegin(GL_POINTS);
        glVertex2i(x, y);
        glEnd();
    }
    glFlush();
}

void init(void)
{
    glClearColor(0.7, 0.7, 0.7, 0.7);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0, 300, 0, 300);
}

int main(int argc, char** argv) {
    printf("Enter the value of x1 : ");
    scanf("%f", &x1);
    printf("Enter the value of y1 : ");
    scanf("%f", &y1);
    printf("Enter the value of x2 : ");
    scanf("%f", &x2);
    printf("Enter the value of y2 : ");
    scanf("%f", &y2);

    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(500, 500);
    glutInitWindowPosition(100, 100);
    glutCreateWindow("GLTUT: DDA Line Algo");
    init();
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop();

    return 0;
}