#include "circle.h"

void drawCircle(Circle circle){
	drawQuadrant(circle.q1);
	drawQuadrant(circle.q2);	
	drawQuadrant(circle.q3);	
	drawQuadrant(circle.q4);	
}

void drawQuadrant(Quadrant quadrant){
	drawOctet(quadrant.oct1);
	drawOctet(quadrant.oct2);
}

void drawOctet(Octet octet){
	for (GLint i=0; i<octet.points.size(); i++) {
		glBegin(GL_POINTS);
		glVertex2i(octet.points[i].x, octet.points[i].y); 
		glEnd();
	}
}

void drawFilledCircle(Circle circle){
	glBegin(GL_TRIANGLE_FAN);
	glVertex2i(0, 0); 
	drawFilledQuadrant(circle.q1);
	drawFilledQuadrant(circle.q2);	
	drawFilledQuadrant(circle.q3);	
	drawFilledQuadrant(circle.q4);	
	glEnd();
}

void drawFilledQuadrant(Quadrant quadrant){
	drawFilledOctet(quadrant.oct1);
	drawFilledOctet(quadrant.oct2);
}

void drawFilledOctet(Octet octet){
	for (GLint i=0; i<octet.points.size(); i++) {
		glVertex2i(octet.points[i].x, octet.points[i].y); 
	}
}
