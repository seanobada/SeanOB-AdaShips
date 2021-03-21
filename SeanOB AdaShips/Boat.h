#pragma once
#include <string>
class Boat
{
private:
	int coordX;
	int coordY;
	bool isVertical;
	int size;
	std::string name;
	bool isDestroyed;
public:
	void SetBoatPosition(int coordX, int coordY);
};

