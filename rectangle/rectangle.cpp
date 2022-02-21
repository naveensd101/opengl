#include <GL/freeglut.h>
#include <GL/gl.h>
#include <iostream>
#include <vector>
using namespace std;
/*
to run: g++ main.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
*/
void keyboard(unsigned char key, int x, int y) {
    switch (key) {
    case 27:
        exit(0);
        break;
    }
}
void renderFunction() {
  glClear(GL_DEPTH_BUFFER_BIT);
  glClearColor(0, 0, 0, 1);
  glClear(GL_COLOR_BUFFER_BIT);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);
  glDepthFunc(GL_LESS);

  freopen("points2.txt", "r", stdin);
  for(int i = 0; i < 3; ++i) {
    switch(i) {
      case 0:
        glColor3f(1, 0, 0);
        break;
      case 1:
        glColor3f(0, 1, 0);
        break;
      case 2:
        glColor3f(0, 0, 1);
        break;
    }
    glBegin(GL_POLYGON);
    for(int j = 0; j < 3; ++j) {
      float x, y, z;
      cin >> x >> y >> z;
      glVertex3f(x, y, z);
    }
    glEnd();
  }
  glFlush();
}
int main (int argc, char** argv) {
  glutInit(&argc, argv);
  //GLUT_DEPTH is for depth buffer
  glutInitDisplayMode(GLUT_RGB | GLUT_SINGLE | GLUT_DEPTH);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 200);
  glutCreateWindow("SD with OpenGL");

  glEnable(GL_DEPTH_TEST);

  glutKeyboardFunc(keyboard);
  glutDisplayFunc(renderFunction);


  glutMainLoop();
  return 0;
}
