#include <GL/freeglut.h>
#include <GL/gl.h>
#include <random>

float rf() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    return dis(gen);
}
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
      exit(0);
      break;
  }
}

void fractal(double k, double x1, double y1, double x2, double y2, double x3, double y3, double x4, double y4) {
  //draw a polygon with xi, yi as vertices
  glBegin(GL_LINE_LOOP);
  glVertex2f(x1, y1);
  glVertex2f(x2, y2);
  glVertex2f(x3, y3);
  glVertex2f(x4, y4);
  glEnd();

  glFlush();
  //recursive call
  if(k == 0) {
    return;
  }
  fractal(k-1, 
      (x1+x2)/2, (y1+y4)/2,
      x2, (y2+y3)/2,
      x3, y3,
      (x1+x2)/2, y4
      );
  fractal(k-1,
      x1, y1,
      (x1+x2)/2, y1,
      (x1+x2)/2, (y1+y4)/2,
      x1, (y1+y4)/2
      );
}
void renderFunction() {
  glClearColor(0.25, 0.25, 0.25, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  //glColor3f specifies the red, green, and blue values used by subsequent calls to glVertex3f.
  glColor3f(0.8, 1.0, 1.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  fractal(10, -0.75, -0.75, 0.75, -0.75, 0.75, 0.75, -0.75, 0.75);
}
int main (int argc, char** argv) {
  //glutInit initializes the GLUT library. and negotiate a session with the window system.
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(0, 200);
  glutCreateWindow("SD with OpenGL");
  //glutDisplayFunc is called when the window needs to be redrawn.
  glutDisplayFunc(renderFunction);
  //keyboard callback
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}
