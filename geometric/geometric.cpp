//write a open gl code to draw line sement between points that are taken from points.txt file
#include <GL/glut.h>
#include <GL/gl.h>
#include <GL/glu.h>
#include <GL/freeglut.h>
#include <iostream>
#include <vector>
using namespace std;

void display() {
  glClear(GL_COLOR_BUFFER_BIT);
  glColor3f(1.0, 0.0, 0.0);

  freopen("points.txt", "r", stdin);
  vector<pair<float, float>> points;
  int n;
  cin >> n;
  for(int i = 0; i < n; i++) {
    float x, y;
    cin >> x >> y;
    points.push_back(make_pair(x, y));
  }
  for(int i = 0; i < points.size(); i++) {
    for(int j = 0; j < points.size(); j++) {
      if(i != j) {
        glBegin(GL_LINES);
        glVertex2f(points[i].first, points[i].second);
        glVertex2f(points[j].first, points[j].second);
        glEnd();
      }
    }
  }

  glFlush();
}
void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  }
}
int main(int argc, char** argv) {
  glutInit(&argc, argv);
  glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
  glutInitWindowSize(500, 500);
  glutInitWindowPosition(100, 100);
  glutCreateWindow("Line");
  //take in keyboard input
  glutKeyboardFunc(keyboard);
  glutDisplayFunc(display);
  glutMainLoop();
  return 0;
}

