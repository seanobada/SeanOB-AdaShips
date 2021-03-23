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
			if (board[x][y].GetIsRevealed() == true)
			{
				std::cout << std::setw(1) << board[x][y].GetTileValue() << " | ";
			}
			else
			{
				std::cout << std::setw(1) << '~' << " | ";
			}
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

	if (minBounds1.x <= maxBounds2.x &&
		maxBounds1.x >= minBounds2.x &&
		minBounds1.y <= maxBounds2.y &&
		maxBounds1.y >= minBounds2.y)
	{
		return true;
	}
	return false;
}

void Board::AddBoat(Boat boat)
{
	boats.push_back(boat);
}

Tile& Board::GetTileAtCoord(Coordinate coord)
{
	return board[coord.y][coord.x];
}

int Board::GetWidth()
{
	return cols;
}
int Board::GetHeight()
{
	return rows;
}

Boat* Board::GetBoatAtCoord(Coordinate coord)
{
	for (size_t i = 0; i < boats.size(); i++)
	{
		Coordinate minBounds = boats[i].GetPosition();
		Coordinate maxBounds;
		if (boats[i].GetIsVertical() == false)
		{
			maxBounds.x = boats[i].GetPosition().x + (boats[i].GetSize() - 1);
			maxBounds.y = boats[i].GetPosition().y;
		}
		else
		{
			maxBounds.x = boats[i].GetPosition().x;
			maxBounds.y = boats[i].GetPosition().y + (boats[i].GetSize() - 1);
		}

		if (minBounds.x <= coord.x &&
			maxBounds.x >= coord.x &&
			minBounds.y <= coord.y &&
			maxBounds.y >= coord.y)
		{
			return &boats[i];
		}
	}
	return nullptr;
}

bool Board::CheckBoatDestroyed(Boat boat)
{
	Coordinate c;
	c = boat.GetPosition();
	for (size_t i = 0; i < boat.GetSize(); i++)
	{
		if (board[c.y][c.x].GetIsDamaged() == false)
		{
			return false;
		}

		if (boat.GetIsVertical() == true)
		{
			c.y += 1;
		}
		else
		{
			c.x += 1;
		}
	}
	return true;
}

void Board::RevealBoat(Boat boat)
{
	Coordinate c;
	c = boat.GetPosition();
	for (size_t i = 0; i < boat.GetSize(); i++)
	{
		board[c.y][c.x].SetTileValue(boat.GetName()[0]);
		if (boat.GetIsVertical() == true)
		{
			c.y += 1;
		}
		else
		{
			c.x += 1;
		}
	}
}

int Board::GetUndamagedTilesCount()
{
	int totalAliveTiles = 0;
	for (size_t x = 0; x < rows; x++)
	{
		for (size_t y = 0; y < cols; y++)
		{
			if (board[x][y].GetIsDamaged() == false)
			{
				totalAliveTiles++;
			}
		}
	}
	return totalAliveTiles;
}

void Board::Unreveal()
{
	for (size_t x = 0; x < rows; x++)
	{
		for (size_t y = 0; y < cols; y++)
		{
			board[x][y].SetIsRevealed(false);
		}
	}
}