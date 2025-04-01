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
	glBegin (GL_LINE_STRIP);
	glVertex2i (30, 30); 
	glVertex2i (0, 60); 
	glVertex2i (30, 90); 
	glVertex2i (60, 60); 
	glEnd ();
	glFlush();
}

void shapeB ()
{
	glColor3f (0.0, 0.0, 0.0); 
	glBegin (GL_LINE_STRIP);
	glVertex2i (100, 30); 
	glVertex2i (80, 40); 
	glVertex2i (70, 60); 
	glVertex2i (80, 80); 
	glVertex2i (100, 90); 
	glVertex2i (120, 80); 
	glVertex2i (130, 60); 
	glEnd ();
	glFlush (); 
}

void shapeC ()
{
	glColor3f (0.0, 0.0, 0.0); 
	glBegin (GL_LINE_STRIP);
	glVertex2f (170, 30); 
	glVertex2f (160, 32.5); 
	glVertex2f (150, 40); 
	glVertex2f (142.5, 50); 
	glVertex2f (140, 60); 
	glVertex2f (142.5, 70); 
	glVertex2f (150, 80); 
	glVertex2f (160, 87.5); 
	glVertex2f (170, 90); 
	glVertex2f (180, 87.5); 
	glVertex2f (190, 80); 
	glVertex2f (197.5, 70); 
	glVertex2f (200, 60); 
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
	glutInitWindowSize (1200, 1200); 
	glutCreateWindow ("Assignment 1"); 
	init (); 
	glutDisplayFunc (drawShapes); 
	glutMainLoop (); 
}
