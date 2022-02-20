/*
 * random color generator: when you click any button, it will generate a random color
 * to exit use the escape key
 * it will also print the x and y coordinates of the mouse and the key pressed
 */
#include <GL/freeglut.h>
#include <GL/gl.h>
#include <stdio.h>
#include <iostream>
#include <random>
GLfloat r = 1.0, g = 1.0, b = 1.0, a = 0.0;

void MykeyboardFunc(unsigned char key, int x, int y) {
  printf("x = %d, y = %d\n", x, y);
  printf("int equvalent of key = %d\n", key);
  r = (float)rand() / (float)RAND_MAX;
  g = (float)rand() / (float)RAND_MAX;
  b = (float)rand() / (float)RAND_MAX;
  a = (float)rand() / (float)RAND_MAX;
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
  glFlush();
  if(key == 27) {
    exit(0);
  }
}
void renderFunction() {
  int i = 0;
  glClearColor(r, g, b, a);
  glClear(GL_COLOR_BUFFER_BIT);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  glFlush();
}

int main(int argc, char **argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Keyboard");

  //registering a keyboard event callback.
  //MykeyboardFunc will now get called on any key press.
  glutKeyboardFunc(MykeyboardFunc);

  glutDisplayFunc(renderFunction);
  glutMainLoop();
  return 0;
}

