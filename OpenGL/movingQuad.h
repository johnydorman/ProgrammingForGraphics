#pragma once
class movingQuad {
public:
	movingQuad(int, int, int, int);
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
	int speed;
	int size;
};