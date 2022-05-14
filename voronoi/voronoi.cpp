#include <GL/freeglut.h>
#include <GL/gl.h>
#include <sstream>
#include <vector>
#include <iostream>
#include <cmath>

void keyboard(unsigned char key, int x, int y) {
  switch (key) {
  case 27:
    exit(0);
    break;
  }
}
void renderFunction() {
  glClearColor(1.0, 1.0, 1.0, 1.0);
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
  glBegin(GL_POINTS);
  for (auto point : points) {
    glVertex2f(point.first, point.second);
  }
  glEnd();

  //draw voronoi diagram
  //points vector has all the points
  //now we will brute force the voronoi diagram
  //for each point, we will find the closest point
  //and draw a line between them
  //we will do this for all points
  for(int x = 0; x <= 500; x++) {
    for(int y = 0; y <= 500; y++) {
      std::vector<double> distances(points.size());
      for(int i = 0; i < points.size(); i++) {
        distances[i] = sqrt(pow(points[i].first - x, 2) + pow(points[i].second - y, 2));
      }
      //if any two of the distances are the same, then we have a tie
      //and we will change that particular pixel to red
      bool flag = false;
      for(int i = 0; i < distances.size(); i++) {
        for(int j = i + 1; j < distances.size(); j++) {
          if(distances[i] - distances[j] < 0.00001) {
            flag = true;
          }
        }
      }
      if(flag) {
        glColor3f(1.0, 0.0, 0.0);
        //convert x and y to a point in the cartition plane
        double H = glutGet(GLUT_WINDOW_HEIGHT);
        double W = glutGet(GLUT_WINDOW_WIDTH);
        double X = ((float)x - W / 2) / (W / 2);
        double Y = ((H - (float)y) - H / 2) / (H / 2);
        glBegin(GL_POINTS);
        glVertex2f(X, Y);
        glEnd();
      }
      else {
        glColor3f(0.0, 0.0, 1.0);
        //convert x and y to a point in the cartition plane
        double H = glutGet(GLUT_WINDOW_HEIGHT);
        double W = glutGet(GLUT_WINDOW_WIDTH);
        double X = ((float)x - W / 2) / (W / 2);
        double Y = ((H - (float)y) - H / 2) / (H / 2);
        glBegin(GL_POINTS);
        glVertex2f(X, Y);
        glEnd();
      }
    }
  }
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
  glutKeyboardFunc(keyboard);
  glutMainLoop();
  return 0;
}


