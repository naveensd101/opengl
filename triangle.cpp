#include <GL/freeglut.h>
#include <GL/gl.h>
/*
to run: g++ main.c -lglut -lGL -lGLEW -lGLU -o OpenGLExample
*/
void renderFunction() {
  //glClearColor specifies the rgb alpha values used by glClear to clear the color buffer.
  //value is between 0.0 and 1.0
  glClearColor(0.25, 0.25, 0.25, 0.0);
  //glClear clears the buffers specified by mask.
  //GL_COLOR_BUFFER_BIT specifies the color buffer.
  glClear(GL_COLOR_BUFFER_BIT);
  //glColor3f specifies the red, green, and blue values used by subsequent calls to glVertex3f.
  glColor3f(0.8, 1.0, 1.0);
  //glOrtho specifies a 2D orthographic projection matrix.
  //it describes the field of vision of the camera specified by a cuboid of certain dimensions.
  //the projection matrix is used to transform the 3D coordinates of the vertices of the triangles to 2D coordinates.
  //glOrtho specifies the left, right, bottom, and top dimensions of the view volume.
  glOrtho(-1.0, 1.0, -1.0, 1.0, -1.0, 1.0);

  //using window size as the view volume
  //glMatrixMode(GL_PROJECTION);
  //glLoadIdentity();
  //double windowWidth = glutGet(GLUT_WINDOW_WIDTH);
  //double windowHeight = glutGet(GLUT_WINDOW_HEIGHT);
  //glOrtho(0.0f, windowWidth, windowHeight, 0.0f, 0.0f, 1.0f);
  //glBegin specifies the type of primitives to be rendered.
  //GL_LINES specifies that the primitives are lines.
  //GL_POINTS specifies that the primitives are points.
  //GL_POLYGON specifies that the primitives are polygons.
  glBegin(GL_POLYGON);
  glVertex2f(1, 1);
  glVertex2f(-0.25, 0.25);
  glVertex2f(-0.5, -0.5);
  glVertex2f(0.5, -0.5);
  glEnd();

  //glFlush causes the output to be displayed.
  glFlush();
}
int main (int argc, char** argv) {
  //glutInit initializes the GLUT library. and negotiate a session with the window system.
  glutInit(&argc, argv);
  //glutInitDisplayMode sets the display mode.
  //GLUT_DOUBLE is a display mode that allows double buffering.
  //GLUT_RGB is a display mode that allows RGB colors.
  //add GLUT_DEPTH if you need depth functionality also See rectangle/rectangle.cpp
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
