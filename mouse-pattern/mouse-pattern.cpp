#include <GL/freeglut.h>
#include <GL/gl.h>
#include <sstream>
#include <vector>
#include <iostream>
using namespace std;

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  case 'r':
    glClearColor(0.0, 0.0, 0.0, 0.0);
    glClear(GL_COLOR_BUFFER_BIT);
    glFlush();
    break;
  }
}

void glutMotion(int x, int y) {
  cout << "x: " << x << " y: " << y << endl;
  float H = glutGet(GLUT_WINDOW_HEIGHT);
  float W = glutGet(GLUT_WINDOW_WIDTH);
  float X = ((float)x - W / 2) / (W / 2);
  float Y = ((H - (float)y) - H / 2) / (H / 2);

  glColor3f(1.0, 0, 0);
  glPointSize(5);
  glBegin(GL_LINES);
  glVertex2f(0,0);
  glVertex2f(X, Y);
  glEnd();
  glFlush();
}

void mouse(int button, int state, int x, int y) {
  if (0 and button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    float H = glutGet(GLUT_WINDOW_HEIGHT);
    float W = glutGet(GLUT_WINDOW_WIDTH);
    float X = ((float)x - W / 2) / (W / 2);
    float Y = ((H - (float)y) - H / 2) / (H / 2);

    glColor3f(1.0, 0, 0);
    glPointSize(5);
    glBegin(GL_POINTS);
    glVertex2f(X, Y);
    glEnd();
    glFlush();
  }
}

void renderFunction() {
  glClearColor(0.0, 0.0, 0.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);
  glPointSize(5.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glFlush();
}
int main (int argc, char** argv) {
  //glutInit initializes the GLUT library. and negotiate a session with the window system.
  glutInit(&argc, argv);
  //glutInitDisplayMode sets the display mode.
  //GLUT_DOUBLE is a display mode that allows double buffering.
  //GLUT_RGB is a display mode that allows RGB colors.
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  //glutInitWindowSize sets the width and height of the window.
  //but window size and position can be different
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 200);
  glutCreateWindow("SD with OpenGL");

  //glutKeyboardFunc sets the keyboard callback function.
  glutKeyboardFunc(keyboard);
  //glutMouseFunc sets the mouse callback function.
  glutMouseFunc(mouse);
  //glutMotionFunc sets the motion callback function.
  glutMotionFunc(glutMotion);
  //glutDisplayFunc is called when the window needs to be redrawn.
  glutDisplayFunc(renderFunction);
  //glutMainLoop enters the GLUT event processing loop.
  //should be called only once.
  //glutMainLoop never returns.
  glutMainLoop();
  return 0;
}


