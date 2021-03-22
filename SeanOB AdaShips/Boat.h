#pragma once
#include <string>

#include "Coordinate.h"
class Boat
{
private:
	Coordinate position;
	bool isVertical = true;
	int size = 1;
	std::string name = "";
	bool isDestroyed = false;
public:
	void SetPosition(Coordinate coord);
	Coordinate GetPosition();
	bool GetIsDestroyed();
	void SetIsVertical(bool value);
	bool GetIsVertical();
	void SetSize(int size);
	int GetSize();
	void SetName(std::string name);
	std::string GetName();
};

