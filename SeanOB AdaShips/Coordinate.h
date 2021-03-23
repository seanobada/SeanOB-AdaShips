#pragma once

#include <string>
struct Coordinate
{
	int x;
	int y;
	Coordinate(int newX, int newY);
	Coordinate();
	std::string ToBoardCoord();
	void SetBoardCoord(std::string x, std::string y);

};

