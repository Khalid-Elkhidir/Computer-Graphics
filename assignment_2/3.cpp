#include <GL/glut.h> 
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "utils.h"
using namespace std;

const double TWO_PI = 2.0 * M_PI;
typedef enum { limacon = 1, cardioid, threeLeaf, fourLeaf, spiral } curveName;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (0.0, 1000.0, 0.0, 1000.0);
}

void lineSegment (Point pt1, Point pt2)
{
	glBegin (GL_LINES);
	glVertex2i (pt1.x, pt1.y);
	glVertex2i (pt2.x, pt2.y);
	glEnd ();
}

void drawCurve (GLint curveNum, GLint x0, GLint y0)
{
	const GLint a = 100, b = 50;
	GLfloat r, theta, dtheta = 1.0 / float (a);
	Point curvePt[2];
	glColor3f (0.0, 0.0, 0.0);
	curvePt[0].x = x0;
	curvePt[0].y = y0;

	switch (curveNum) {
		case limacon: curvePt[0].x += a + b; break;
		case cardioid: curvePt[0].x += a + a; break;
		case threeLeaf: curvePt[0].x += a; break;
		case fourLeaf: curvePt[0].x += a; break;
		case spiral: break;
		default: break;
	}

	theta = dtheta;
	while (theta < TWO_PI) {
		switch (curveNum) {
			case limacon:
				r = a * cos (theta) + b;
				break;
			case cardioid:
				r = a * (1 + cos (theta));
				break;
			case threeLeaf:
				r = a * cos (3 * theta);
				break;
			case fourLeaf:
				r = a * cos (2 * theta);
				break;
			case spiral:
				r = (a / 4.0) * theta;
				break;
			default:
				break;
		}

		curvePt[1].x = x0 + r * cos (theta);
		curvePt[1].y = y0 + r * sin (theta);
		lineSegment (curvePt[0], curvePt[1]);
		curvePt[0].x = curvePt[1].x;
		curvePt[0].y = curvePt[1].y;
		theta += dtheta;
	}
}

void drawShapes() {
	glColor3f (0.0, 0.0, 0.0); 
	glClear (GL_COLOR_BUFFER_BIT); 
	drawCurve(1, 200, 200);
	drawCurve(2, 500, 200);
	drawCurve(3, 300, 550);
	drawCurve(4, 600, 550);
	drawCurve(5, 450, 850);
	glFlush();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (100, 100); 
	glutInitWindowSize (1000, 1000); 
	glutCreateWindow ("Assignment 2.2"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
