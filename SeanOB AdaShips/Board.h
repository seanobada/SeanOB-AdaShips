#pragma once
#include <vector>
#include <iostream>

#include "Tile.h"
#include "Boat.h"

class Board
{
private:

	std::vector<std::vector<Tile>> board;
	int rows, cols;
public:
	void setUpBoard(int width, int height);
	void printBoard();
};

