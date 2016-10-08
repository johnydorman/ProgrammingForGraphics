#pragma once
class movingQuad {
public:
	movingQuad(int size, int xCenter, int yCenter, float speed);
	void move();
//	std::string toString();

	int getMinX();
	int getMaxX();
	int getMinY();
	int getMaxY();

	int xCenter;
	int yCenter;
	int xGain;
	int yGain;
private:
	float m_speed;
	int m_size;
};