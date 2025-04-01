#ifndef UTILS_H
#define UTILS_H

typedef struct {
	int x;
	int y;
} Point;

typedef struct {
	Point center;
	int r;
} Circle;

void pointSet(int x, int y, Point *point);
#endif
