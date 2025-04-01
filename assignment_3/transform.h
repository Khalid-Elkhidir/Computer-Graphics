#ifndef TRANSFORM_H
#define TRANSFORM_H

#include <GL/glut.h>
#include "utils.h"

void transform(Point *pts, GLint n, GLfloat (*transMat)[3]) {
	GLfloat resMat[3] = {0, 0, 0};
	GLfloat ptMat[3] = {0, 0, 0};

	for(GLint m=0; m<n; m++) {
		ptMat[0] = pts[m].x;
		ptMat[1] = pts[m].y;
		ptMat[2] = 1;
		for(GLint i=0; i<3; i++) {
			for(GLint j=0; j<3; j++) {
				resMat[i] += transMat[i][j] * ptMat[j];
			}
		}
		pts[m].x = resMat[0];
		pts[m].y = resMat[1];

		resMat[0] = 0;
		resMat[1] = 0;
		resMat[2] = 0;
	}
}

void mulMat(GLfloat (*leftMat)[3], GLfloat (*rightMat)[3], GLfloat (*resMat)[3]) {

	for(GLint i=0; i<3; i++) {
		for(GLint j=0; j<3; j++) {
			resMat[i][j] += leftMat[i][j] * rightMat[i][j];
		}
	}
}

#endif
