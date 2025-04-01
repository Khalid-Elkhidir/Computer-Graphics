#include<GL/glut.h>
#include<iostream>
#include<sstream>
#include<vector>
#include<math.h>
using namespace std;

typedef GLint vertex3 [3];
vertex3 pt [8] = { {0, 0, 0}, {0, 1, 0}, {1, 0, 0}, {1, 1, 0}, {0, 0, 1}, {0, 1, 1}, {1, 0, 1}, {1, 1, 1} };

void quad (GLint n1, GLint n2, GLint n3, GLint n4)
{
	glBegin (GL_QUADS);
	glVertex3iv (pt [n1]);
	glVertex3iv (pt [n2]);
	glVertex3iv (pt [n3]);
	glVertex3iv (pt [n4]);
	glEnd ( );
}
void cube ( )
{
	glColor3f (0.0, 0.0, 0.0);
    glClear (GL_COLOR_BUFFER_BIT);
	glEnableClientState (GL_VERTEX_ARRAY);
	glVertexPointer (3, GL_INT, 0, pt);
	GLubyte vertIndex [ ] = {6, 2, 3, 7, 5, 1, 0, 4, 7, 3, 1, 5, 4, 0, 2, 6, 2, 0, 1, 3, 7, 5, 4, 6};
	glDrawElements (GL_QUADS, 24, GL_UNSIGNED_BYTE, vertIndex);
	glFlush();
}

void init (void)
{
	glClearColor (1.0, 1.0, 1.0, 0.0);
//	glMatrixMode (GL_PROJECTION);
	gluOrtho2D (-5.0, 5.0, -5.0, 5.0);
}

int main(int argc, char **argv)
{
	glutInit (&argc, argv);
	glutInitDisplayMode (GLUT_SINGLE | GLUT_RGB);
	glutInitWindowPosition (100, 100);
	glutInitWindowSize (1000, 1000);
	glutCreateWindow ("Assignment 2.3");
	init ();
	glutDisplayFunc (cube);
	glutMainLoop ();
}	
