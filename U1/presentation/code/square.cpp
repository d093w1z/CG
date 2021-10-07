#include <GL/glut.h>
#include <iostream>

using namespace std;

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
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
    glVertex3f(2.0, 2.0, 1.0);
    glVertex3f(8.0, 2.0, 1.0);
    glVertex3f(8.0, 8.0, -1.0);
    glVertex3f(2.0, 8.0, -1.0);
    glEnd();
    glPopMatrix();
    glFlush();
}

int main(int argc, char** argv) {

    glutInit(&argc, argv);                      // initialises glut
    glutInitDisplayMode(                        // used to set display modes
        GLUT_SINGLE |                           // has a single buffer; double buffers not required as static scene
        GLUT_RGB |                              // sets color mode to RGB
        GLUT_DEPTH                              // Depth value, used for Z-buffer
    );
    glutInitWindowPosition(100, 100);           // sets window position on screen
    glutInitWindowSize(300, 300);               // sets window size
    glutCreateWindow("GLTUT: square");          // creates and sets the title of window
    glClearColor(0.0, 0.0, 0.0, 0.0);           // black background, used everytime glClear(); is called

    glMatrixMode(GL_PROJECTION);                // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(0.0, 10.0, 0.0, 10.0, -1.0, 1.0);   // setup a 10x10x2 viewing world
    glutDisplayFunc(display);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop();
    return 0;
}
