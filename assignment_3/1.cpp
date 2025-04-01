#include <GL/glut.h> 
#include "transform.h"

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (-400.0, 400.0, -400.0, 400.0);
}

void drawRect(Point pt1, Point pt2) {
	glColor3f(0.4, 0.4, 0.4);
	glRecti(pt1.x, pt1.y, pt2.x, pt2.y);
}

void drawShapes() {
	GLint n=2;
	
	Point pt1, pt2;
	pt1 = {50, 100};
	pt2 = {200, 150};
	Point pts[n] = {pt1, pt2};

	GLfloat tx, ty;
	tx = -200.0;
	ty = -50.0;
	GLfloat transMat [3][3] = {{1, 0, tx}, {0, 1, ty}, {0, 0, 1}};

	transform(pts, n, transMat);

	glClear (GL_COLOR_BUFFER_BIT); 
	drawRect(pts[0], pts[1]);
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (100, 100); 
	glutInitWindowSize (1000, 1000); 
	glutCreateWindow ("Assignment 3.1"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
