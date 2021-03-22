#pragma once
#include <vector>
#include <iostream>

#include "Tile.h"
#include "Boat.h"

class Board
{
private:

	std::vector<std::vector<Tile>> board;
	std::vector<Boat> boats;
	int rows, cols;
public:
	void setUpBoard(int width, int height);
	void PrintBoard();
	int BoatsRemaining();
	bool IsBoatPositionValid(Boat boat);
	bool CheckBoatCollision(Boat boat1, Boat boat2);
	void AddBoat(Boat boat);
	Tile& GetTileAtCoord(Coordinate coord);
	
};

