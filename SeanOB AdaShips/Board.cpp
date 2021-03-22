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
	std::cout << std::endl << std::setw(7) << ""; 
	for (size_t i = 0; i < cols; i++)
	{
		C.x = i;
		std::cout << std::setw(2) << FileReader::Instance().split(C.ToBoardCoord(), ',', 0) << " |";
	}
	std::cout << std::endl;	

	
	for (int x = 0, cnt = 1; x < rows; x++)
	{
		C.y = x;
		std::cout << std::setw(5) << FileReader::Instance().split(C.ToBoardCoord(), ',', 1) << " | ";
		for (int y = 0; y < cols; y++)
		{
			std::cout << std::setw(1) << board[x][y].GetTileValue() << " | ";
		}
		std::cout << std::endl;
	}
}
int Board::BoatsRemaining()
{
	int boatsCount = 0;
	for (size_t i = 0; i < boats.size(); i++)
	{
		if (boats[i].GetIsDestroyed() == false)
		{
			boatsCount++;
		}
		
	}
	return boatsCount;
}

bool Board::IsBoatPositionValid(Boat boat)
{
	Coordinate minBounds = boat.GetPosition();
	Coordinate maxBounds;
	if (boat.GetIsVertical() == false)
	{
		maxBounds.x = boat.GetPosition().x + (boat.GetSize() - 1);
		maxBounds.y = boat.GetPosition().y;
	}
	else
	{
		maxBounds.x = boat.GetPosition().x;
		maxBounds.y = boat.GetPosition().y + (boat.GetSize() - 1);
	}

	if (minBounds.x < 0 || minBounds.y < 0 || maxBounds.x > (cols - 1) || maxBounds.y > (rows - 1))
	{
		return false;
	}

	for (size_t i = 0; i < boats.size(); i++)
	{
		if (CheckBoatCollision(boat, boats[i]) == true)
		{
			return false;
		}
	
	}
	return true;
}

bool Board::CheckBoatCollision(Boat boat1, Boat boat2)
{
	Coordinate minBounds1 = boat1.GetPosition();
	Coordinate maxBounds1;
	if (boat1.GetIsVertical() == false)
	{
		maxBounds1.x = boat1.GetPosition().x + (boat1.GetSize() - 1);
		maxBounds1.y = boat1.GetPosition().y;
	}
	else
	{
		maxBounds1.x = boat1.GetPosition().x;
		maxBounds1.y = boat1.GetPosition().y + (boat1.GetSize() - 1);
	}

	Coordinate minBounds2 = boat2.GetPosition();
	Coordinate maxBounds2;
	if (boat2.GetIsVertical() == false)
	{
		maxBounds2.x = boat2.GetPosition().x + (boat2.GetSize() - 1);
		maxBounds2.y = boat2.GetPosition().y;
	}
	else
	{
		maxBounds2.x = boat2.GetPosition().x;
		maxBounds2.y = boat2.GetPosition().y + (boat2.GetSize() - 1);
	}

	if (minBounds1.x < maxBounds2.x &&
		maxBounds1.x > minBounds2.x &&
		minBounds1.y < maxBounds2.y &&
		maxBounds1.y > minBounds2.y)
	{
		return true;
	}
	return false;
}