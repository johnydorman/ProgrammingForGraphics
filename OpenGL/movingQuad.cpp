#include "movingQuad.h"
#include <string>;

movingQuad::movingQuad(int qsize, int qxCenter, int qyCenter, int qspeed)
{
	int xCenter(qxCenter);
	int yCenter(qyCenter);
	int size(qsize);
	int speed(qspeed);
}

void movingQuad::move() {
	xCenter += xGain*speed;
	yCenter += yGain*speed;
}

int movingQuad::getMaxX() {
	return xCenter + size;
}
int movingQuad::getMinX() {
	return xCenter - size;
}

int movingQuad::getMaxY() {
	return yCenter + size;
}
int movingQuad::getMinY() {
	return yCenter - size;
}

//std::string movingQuad::toString() {
//	return "blah";// xCenter + "," + yCenter;
//}
