#include "movingQuad.h"
#include <string>;

movingQuad::movingQuad(int size, int qxCenter, int qyCenter, float speed)
{
	xGain = 1;
	yGain = 1;

	xCenter = qxCenter;
	yCenter = qyCenter;
	m_size = size;
	m_speed =speed;

}

void movingQuad::move() {
	xCenter += xGain*m_speed;
	yCenter += yGain*m_speed;
}

int movingQuad::getMaxX() {
	return xCenter + m_size;
}
int movingQuad::getMinX() {
	return xCenter - m_size;
}

int movingQuad::getMaxY() {
	return yCenter + m_size;
}
int movingQuad::getMinY() {
	return yCenter - m_size;
}

//std::string movingQuad::toString() {
//	return "blah";// xCenter + "," + yCenter;
//}
