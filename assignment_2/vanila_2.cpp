#include <GL/glut.h> 
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "circle.h"
using namespace std;

const double TWO_PI = 2.0 * M_PI;
GLdouble theta;
GLint x, y, k;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

Circle drawCircle (GLint x_0, GLint y_0, GLint r)
{
	Octet octet;
	glColor3f (0.4, 0.4, 0.4); 
	GLint xNext = 0, yNext = r;
	GLint xPlot = 0, yPlot = 1;
	GLint p = 1 - r;

	while (xPlot < yPlot) {
		if (p < 0) {
			xNext = xNext + 1;
			yNext = yNext;		
			p = p + 2*xNext + 1;
		} else {
			xNext = xNext + 1;
			yNext = yNext -1;		
			p = p - 2*yNext + 2*xNext + 1;
		}
		xPlot = xNext + x_0;
		yPlot = yNext + y_0;
		if (xPlot < yPlot) {
			octet.points.push_back({xPlot, yPlot});
		}
	}

	vector<Point> reversedPoints(octet.points.size()); 
	reverse_copy(octet.points.begin(), octet.points.end(), reversedPoints.begin());
	Octet oct2 = {reversedPoints};

	Quadrant q1;
	q1.oct1 = octet;
	q1.oct2 = oct2; 

	Quadrant q2;
	q2.oct1 = octet;
	q2.oct2 = oct2; 

	Quadrant q3;
	q3.oct1 = octet;
	q3.oct2 = oct2; 

	Quadrant q4;
	q4.oct1 = octet;
	q4.oct2 = oct2; 

	Circle circle = {q1,q2,q3,q4};

	return circle;
}

void drawShapes() {
	Octet octet;
	glClear (GL_COLOR_BUFFER_BIT); 
	Circle circle = drawCircle(0, 0, 10);
	octet = circle.q1.oct2;
	for (int i=0; i<octet.points.size(); i++) {
		printf("%i\t%i\n", octet.points[i].x, octet.points[i].y);
	}
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (100, 100); 
	glutInitWindowSize (1000, 1000); 
	glutCreateWindow ("Assignment 1.1"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
