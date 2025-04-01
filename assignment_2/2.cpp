#include <GL/glut.h> 
#include <math.h>
#include <stdio.h>
#include <algorithm>
#include "circle.h"
using namespace std;

const double TWO_PI = 2.0 * M_PI;
GLdouble sliceAngle, previousSliceAngle = 0.0;
Point piePt;
GLint k, nSlices = 12;

GLfloat dataValues[12] = {10.0, 7.0, 13.0, 5.0, 13.0, 14.0, 3.0, 16.0, 5.0, 3.0, 17.0, 8.0};
GLfloat dataSum = 0.0;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (-500.0, 500.0, -500.0, 500.0);
}

Circle circleMidpoint (GLint x_0, GLint y_0, GLint r)
{
	Octet octet;
	GLint xNext = 0, yNext = r;
	GLint xPlot = 0, yPlot = 1;
	GLint p = 1 - r;

	octet.points.push_back({xNext, yNext});

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
		octet.points.push_back({xPlot, yPlot});
	}

	vector<Point> reversedPoints(octet.points.size()); 
	reverse_copy(octet.points.begin(), octet.points.end(), reversedPoints.begin());
	Octet oct2 = {reversedPoints};
	oct2.swap();
	oct2.toString();

	Quadrant q1;
	q1.oct1 = octet;
	q1.oct2 = oct2; 

	Quadrant q2;
	q2.oct1 = oct2; 
	q2.oct2 = octet;
	q2.mul(-1, 1);

	Quadrant q3;
	q3.oct1 = octet;
	q3.oct2 = oct2; 
	q3.mul(-1, -1);

	Quadrant q4;
	q4.oct1 = oct2; 
	q4.oct2 = octet;
	q4.mul(1, -1);

	Point ctr = {x_0, y_0};
	Circle circle = {ctr, r, q1, q2, q3, q4};

	return circle;
}

void drawPieChart(Point circCtr, GLint radius) {

	for (k = 0; k < nSlices; k++)
		dataSum += dataValues[k];

	for (k = 0; k < nSlices; k++) {
		sliceAngle = TWO_PI * dataValues[k] / dataSum + previousSliceAngle;
		piePt.x = circCtr.x + radius * cos (sliceAngle);
		piePt.y = circCtr.y + radius * sin (sliceAngle);
		glBegin (GL_LINES);
		glVertex2i (circCtr.x, circCtr.y);
		glVertex2i (piePt.x, piePt.y);
		glEnd ( );
		previousSliceAngle = sliceAngle;
	}
}

void drawShapes() {
	glColor3f (0.0, 0.0, 0.0); 
	glClear (GL_COLOR_BUFFER_BIT); 
	Circle circle = circleMidpoint(0, 0, 250);
	circle.toString();
	drawCircle(circle);
	drawPieChart(circle.ctr, circle.r);
	glFlush();
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
