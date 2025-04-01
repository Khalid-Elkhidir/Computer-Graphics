#include <GL/glut.h> 
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "utils.h"
using namespace std;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (-250.0, 250.0, -250.0, 250.0);
}

void drawCube(Point origin, GLint width) {
	
	glBegin (GL_POLYGON);
	glVertex2i (origin.x, origin.y);
	glVertex2i (origin.x + width, origin.y);
	glVertex2i (origin.x + width, origin.y + width);
	glVertex2i (origin.x, origin.y + width);
	glEnd ();

	glBegin (GL_POLYGON);
	glVertex2i (origin.x, origin.y + width);
	glVertex2i (origin.x + width, origin.y + width);
	glVertex2i (origin.x + width + 30, origin.y + width + 30);
	glVertex2i (origin.x + 30, origin.y + width + 30);
	glEnd ();

	glBegin (GL_POLYGON);
	glVertex2i (origin.x + width + 30, origin.y + width + 30);
	glVertex2i (origin.x + width, origin.y + width);
	glVertex2i (origin.x + width, origin.y);
	glVertex2i (origin.x + width + 30, origin.y + 30);
	glEnd ();
}

void drawShapes() {
	glColor3f (0.3, 0.3, 0.3); 
	glClear (GL_COLOR_BUFFER_BIT); 
	Point pt = {0, 0};
	drawCube(pt, 100);
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (0, 0); 
	glutInitWindowSize (800, 800); 
	glutCreateWindow ("Title"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
