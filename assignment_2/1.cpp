#include <GL/glut.h> 
#include <math.h>

const double TWO_PI = 2.0 * M_PI;
GLdouble theta;
GLint x, y, k;

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (0.0, 400.0, 0.0, 400.0);
}

void shapeA ()
{
	glColor3f (0.4, 0.4, 0.4); 
	glBegin (GL_POLYGON);
	for (k = 0; k < 6; k++) {
		theta = TWO_PI * k / 6.0;
		x = 200 + 150 * cos (theta);
		y = 200 + 150 * sin (theta);
		glVertex2i (x, y);
	}
	glEnd ( );
	glFlush();
}

void drawShapes() {
	glClear (GL_COLOR_BUFFER_BIT); 
	shapeA();
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
