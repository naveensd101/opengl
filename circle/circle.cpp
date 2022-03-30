#include <GL/freeglut.h>
#include <GL/gl.h>
#include <random>
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
    case 27:
      exit(0);
      break;
    case 'q':
      exit(0);
      break;
  }
}
void renderFunction() {
  glClearColor(0.2, 0.2, 0.2, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0,1,1);
  glBegin(GL_POLYGON);
    //draw a circle with radius of 0.5 and center at (0,0)
    for (int i = 0; i < 360; i++) {
      float degInRad = i * 3.14 / 180;
      glVertex2f(cos(degInRad) * 0.5, sin(degInRad) * 0.5);
    }
  glEnd();
  glLineWidth(3.0);
  glColor3f(0.5, 0.5, 1.0);
  glBegin(GL_LINE_LOOP);
    //draw a circle with radius of 0.5 and center at (0,0)
    for (int i = 0; i < 360; i++) {
      float degInRad = i * 3.14 / 180;
      glVertex2f(cos(degInRad) * 0.5, sin(degInRad) * 0.5);
    }
  glEnd();
  glFlush();
}
int main (int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0,0);
  glutCreateWindow("Circle with SD");
  glutDisplayFunc(renderFunction);
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
