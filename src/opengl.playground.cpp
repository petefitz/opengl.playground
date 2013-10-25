//============================================================================
// Name        : opengl.playground.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <GL/glut.h>
#include <math.h>

#define PI 3.1415926535898

/* Handler for window-repaint event. Call back when the window first appears and
   whenever the window needs to be re-painted. */
void display() {
   glClearColor(0.0f, 0.0f, 0.0f, 1.0f); // Set background color to black and opaque
   glClear(GL_COLOR_BUFFER_BIT);         // Clear the color buffer

   glBegin(GL_POLYGON);
   	  glColor3f(0.0f, 1.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);
      glVertex2f(-0.5f, 0.5f);
      glVertex2f(0.5f, 0.5f);
      glVertex2f(1.0f, 0.0f);
      glVertex2f(0.5f, -0.5f);
   glEnd();

   // Draw a Red 1x1 Square centered at origin
   glBegin(GL_QUADS);              // Each set of 4 vertices form a quad
      glColor3f(1.0f, 0.0f, 0.0f); // Red
      glVertex2f(-0.5f, -0.5f);    // x, y
      glVertex2f( 0.5f, -0.5f);
      glVertex2f( 0.5f,  0.5f);
      glVertex2f(-0.5f,  0.5f);
   glEnd();

   GLint circle_points = 100;
   float angle;
   glBegin(GL_LINE_LOOP);
   glColor3f(0.0f, 0.0f, 1.0f); // Red
   for (int i = 0; i < circle_points; i++) {
	   angle = 2*PI*i/circle_points;
	   glVertex2f(cos(angle), sin(angle));
   }
   glEnd();

   glFlush();  // Render now
}

/* Main function: GLUT runs as a console application starting at main()  */
int main(int argc, char** argv) {
   glutInit(&argc, argv);                 // Initialize GLUT
   //glutInitDisplayMode(GLUT_RGBA | GLUT_DEPTH | GLUT_DOUBLE);
   glutCreateWindow("OpenGL Setup Test"); // Create a window with the given title
   glutInitWindowSize(320, 320);   // Set the window's initial width & height
   glutInitWindowPosition(50, 50); // Position the window's initial top-left corner
   glutDisplayFunc(display); // Register display callback handler for window re-paint
   glutMainLoop();           // Enter the infinitely event-processing loop
   return 0;
}
