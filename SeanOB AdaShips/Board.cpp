#include "Board.h"
#include "FileReader.h"
#include "Tile.h"
void Board::setUpBoard(int width, int height)
{
		
	int cols = width;
	int rows = height;
		
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

void Board::printBoard()
{
	for (int x = 0, cnt = 1; x < rows; x++)
	{
		for (int y = 0; y < cols; y++)
		{
			std::cout << board[x][y].GetTileValue() << "|";
		}
		std::cout << std::endl;
	}
}
