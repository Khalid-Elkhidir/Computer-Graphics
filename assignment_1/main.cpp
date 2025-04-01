#include <GL/glut.h> 

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0); 
	glMatrixMode (GL_PROJECTION); 
	gluOrtho2D (0.0, 200.0, 0.0, 150.0);
}

void shapeA ()
{
	glColor3f (0.0, 0.0, 0.0); 
	glBegin (GL_LINES);
	glVertex2i (60, 70); 
	glVertex2i (10, 20); 
	glVertex2i (30, 90); 
	glVertex2i (50, 20); 
	glVertex2i (0, 70); 
	glEnd ();
	glFlush();
}

void shapeB ()
{
	glColor3f (0.0, 0.0, 0.0); 
	glBegin (GL_LINE_STRIP);
	glVertex2i (130, 70); 
	glVertex2i (80, 20); 
	glVertex2i (100, 90); 
	glVertex2i (120, 20); 
	glVertex2i (70, 70); 
	glEnd ();
	glFlush (); 
}

void shapeC ()
{
	glColor3f (0.0, 0.0, 0.0); 
	glBegin (GL_LINE_LOOP);
	glVertex2i (200, 70); 
	glVertex2i (150, 20); 
	glVertex2i (170, 90); 
	glVertex2i (190, 20); 
	glVertex2i (140, 70); 
	glEnd ();
	glFlush();
}

void drawShapes() {
	glClear (GL_COLOR_BUFFER_BIT); 
	shapeA();
	shapeB();
	shapeC();
}

int main (int argc, char** argv)
{
	glutInit (&argc, argv); 
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB); 
	glutInitWindowPosition (50, 100); 
	glutInitWindowSize (1500, 800); 
	glutCreateWindow ("Assignment 1"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
