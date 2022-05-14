#include <GL/freeglut.h>
#include <GL/gl.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <random>

float rf() {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_real_distribution<> dis(-1, 1);
    return dis(gen);
}
void renderFunction() {
  glClearColor(1.0, 1.0, 1.0, 0.0);
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(0.0, 0.0, 1.0);
  glPointSize(5.0);
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  //take in points values from points.txt
  //open file in stdin stream
  std:: freopen("points.txt", "r", stdin);
  std::vector< std::pair<double, double> > points;
  //read in points
  while(!std::cin.eof()) {
    double x, y;
    std::cin >> x >> y;
    points.push_back(std::make_pair(x, y));
  }
  glBegin(GL_TRIANGLE_FAN);
  for (auto point : points) {
    glColor3f(rf(), rf(), rf());
    //glVertex2f(point.first, point.second);
    glVertex2f(rf(), rf());
  }
  glEnd();
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
  //glutDisplayFunc is called when the window needs to be redrawn.
  glutDisplayFunc(renderFunction);
  //glutMainLoop enters the GLUT event processing loop.
  //should be called only once.
  //glutMainLoop never returns.
  glutMainLoop();
  return 0;
}

