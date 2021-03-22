#pragma once
#include <string>

#include "Coordinate.h"
class Boat
{
private:
	Coordinate position;
	bool isVertical;
	int size;
	std::string name;
	bool isDestroyed;
public:
	void SetPosition(Coordinate coord);
	Coordinate GetPosition();
	bool GetIsDestroyed();
	void SetIsVertical(bool value);
	bool GetIsVertical();
	int GetSize();
};

