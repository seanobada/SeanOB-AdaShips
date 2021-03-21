#include <iomanip>

#include "Board.h"
#include "FileReader.h"
#include "Tile.h"
#include "Coordinate.h"

void Board::setUpBoard(int width, int height)
{

	cols = width;
	rows = height;

	for (int x = 0; x < rows; x++) {
		std::vector<Tile> columns;
		board.push_back(columns);
		for (int y = 0; y < cols; y++)
		{
			Tile t;
			t.SetTileValue('~');
			board[x].push_back(t);
			//board[x].push_back('~');
		}
	}
}



void Board::PrintBoard()
{
	Coordinate C;
	std::cout << std::endl << std::setw(7);
	for (size_t i = 0; i < cols; i++)
	{
		C.x = i;
		std::cout << FileReader::Instance().split(C.ToBoardCoord(), ',', 0) << "|";
	}
	std::cout << std::endl;
	
	for (int x = 0, cnt = 1; x < rows; x++)
	{
		C.y = x;
		std::cout << std::setw(5) << FileReader::Instance().split(C.ToBoardCoord(), ',', 1) << "|";
		for (int y = 0; y < cols; y++)
		{
			std::cout << std::setw(2) << board[x][y].GetTileValue() << "|";
		}
		std::cout << std::endl;
	}
}
