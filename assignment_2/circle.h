#ifndef CIRCLE_H
#define CIRCLE_H

#include <vector>
#include <GL/glut.h>
#include <stdio.h>

class Point {
	public:
		GLint x, y;
		void mul(GLint x, GLint y) {
			this->x *= x;
			this->y *= y;
		}

		void swap() {
			this->x = this->x ^ this->y;
			this->y = this->x ^ this->y;
			this->x = this->x ^ this->y;
		}

		void toString() {
			printf("x:%i\ty:%i\n", x, y);
		}
};

class Octet {
	public:
		std::vector<Point> points;
		void mul (GLint x, GLint y) {
			for (GLint i=0; i<this->points.size(); i++) {
				this->points[i].mul(x, y);
			}
		}

		void swap() {
			for (GLint i=0; i<this->points.size(); i++) {
				this->points[i].swap();
			}
		}

		void toString() {
			for (GLint i=0; i<this->points.size(); i++) {
				this->points[i].toString();
			}
		}
};

class Quadrant {
	public:
		Octet oct1, oct2;
		void mul (GLint x, GLint y) {
			oct1.mul(x, y);
			oct2.mul(x, y);
		}

		void toString() {
			printf("octet1\n");
			oct1.toString();
			printf("octet2\n");
			oct2.toString();
		}
};

class Circle {
	public:
		Point ctr;
		GLint r;
		Quadrant q1, q2, q3, q4;
		void toString() {
			printf("quadrant1\n");
			q1.toString();
			printf("quadrant2\n");
			q2.toString();
			printf("quadrant3\n");
			q3.toString();
			printf("quadrant4\n");
			q4.toString();
		}
};

void drawCircle(Circle);
void drawQuadrant(Quadrant);
void drawOctet(Octet);

void drawFilledCircle(Circle);
void drawFilledQuadrant(Quadrant);
void drawFilledOctet(Octet);

#endif
