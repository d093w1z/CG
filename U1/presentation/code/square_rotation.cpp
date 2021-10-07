#include <GL/glut.h>
#include <iostream>

using namespace std;

int rot=0;

void keyboardHandler(unsigned char c, int x, int y) {
    if (c == '\e') { exit(0); }
    switch (c)
    {
    case '\e':
        exit(0);
        break;
    
    case '+':
        rot+=5;
        rot = rot % 360;
        break;

    default:
        break;
    }
}

void display(void)
{
    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();

    glRotatef(rot, 0.0f, 1.0f, 0.0f);
    glClear(GL_COLOR_BUFFER_BIT);
    glColor3f(0.0, 1.0, 1.0);
    glBegin(GL_POLYGON);
        glColor3f(1.0, 1.0, 1.0);
        glVertex3f(-3.0, -3.0, 0.0);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3f(3.0, -3.0, 0.0);
        glColor3f(0.0, 0.0, 1.0);
        glVertex3f(3.0, 3.0, 0.0);
        glColor3f(0.0, 1.0, 0.0);
        glVertex3f(-3.0, 3.0, 0.0);
    glEnd();
    glPopMatrix();
    glutSwapBuffers();
}

int main(int argc, char** argv) {
    glutInit(&argc, argv);                      // initialises glut
    glutInitDisplayMode(                        // used to set display modes
        GLUT_DOUBLE |                           // has a single buffer; double buffers not required as static scene
        GLUT_RGB |                              // sets color mode to RGB
        GLUT_DEPTH                              // Depth value, used for Z-buffer
    );
    glutInitWindowPosition(100, 100);            // sets window position on screen
    glutInitWindowSize(300, 300);                // sets window size
    glutCreateWindow("GLTUT: square_rotation");          // creates and sets the title of window
    glClearColor(0.0, 0.0, 0.0, 0.0);           // black background, used everytime glClear(); is called
    glMatrixMode(GL_PROJECTION);                // setup viewing projection
    glLoadIdentity();                           // start with identity matrix
    glOrtho(-5.0, 5.0, -5.0, 5.0, -5.0, 5.0);   // setup a 10x10x2 viewing world
    glutDisplayFunc(display);
    glutIdleFunc(display);
    glutKeyboardFunc(keyboardHandler);
    glutMainLoop();
    return 0;
}
