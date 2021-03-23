#include <iostream>
#include <chrono>
#include <thread>

#include "PlayerTurn.h"
#include "Tile.h"
#include "FileReader.h"


void PlayerTurn::DoTurn(Board& opponentBoard, int salvoCount)
{
	std::vector<Coordinate> targetCoords;
	Coordinate c;
	std::string x, y;
	bool isValidInput = true;

	int numberOfTilesAlive = opponentBoard.GetUndamagedTilesCount();
	if (salvoCount > numberOfTilesAlive)
	{
		salvoCount = numberOfTilesAlive;
	}

	for (size_t i = 0; i < salvoCount; i++)
	{
		do
		{
			isValidInput = true;
			if (salvoCount > 1)
			{
				std::cout << "Number of salvos left: " << salvoCount - i << std::endl;
			}
			std::cout << "Enter X coord for your attack: ";
			std::cin >> x;

			std::cout << "Enter Y coord for your attack: ";
			std::cin >> y;

			std::cout << std::endl;
			c.SetBoardCoord(x, y);

			if (c.x > opponentBoard.GetWidth() - 1 || c.y > opponentBoard.GetHeight() - 1 || c.x < 0 || c.y < 0)
			{
				std::cout << "Invalid input! Try again." << std::endl;
				isValidInput = false;
				continue;
			}
			if (opponentBoard.GetTileAtCoord(c).GetIsDamaged() == true)
			{
				std::cout << "It's already been shot!" << std::endl;
				isValidInput = false;
			}
			for (size_t i = 0; i < targetCoords.size(); i++)
			{
				if (c.x == targetCoords[i].x && c.y == targetCoords[i].y)
				{
					isValidInput = false;
				}
			}
		} while (isValidInput == false);
		targetCoords.push_back(c);
	}

	for (size_t i = 0; i < salvoCount; i++)
	{
		std::string currentBoardCoord = targetCoords[i].ToBoardCoord();
		
		std::cout << "Firing at (" << FileReader::Instance().split(currentBoardCoord, ',', 0) << ", " << FileReader::Instance().split(currentBoardCoord, ',', 1) << ")" << std::endl;
		std::this_thread::sleep_for(std::chrono::seconds(1));

		opponentBoard.GetTileAtCoord(targetCoords[i]).SetIsDamaged(true);
		if (opponentBoard.GetTileAtCoord(targetCoords[i]).GetTileValue() != '~')
		{
			std::cout << "Hit!" << std::endl;
			Boat* hitBoat = opponentBoard.GetBoatAtCoord(targetCoords[i]);
			if (opponentBoard.CheckBoatDestroyed(*hitBoat) == true)
			{
				std::cout << "You have Destroyed " << hitBoat->GetName() << "!" << std::endl;
				opponentBoard.RevealBoat(*hitBoat);
				hitBoat->SetIsDestroyed(true);
			}
			else
			{
				opponentBoard.GetTileAtCoord(targetCoords[i]).SetTileValue('X');
			}
		}
		else
		{
			std::cout << "Miss!" << std::endl;
			opponentBoard.GetTileAtCoord(targetCoords[i]).SetTileValue('W');
		}
		opponentBoard.GetTileAtCoord(targetCoords[i]).SetIsRevealed(true);
	}
}

void PlayerTurn::DoBoatPlacement(Board& ownBoard, GameRules gameRules)
{
	for (size_t i = 0; i < gameRules.boatDatas.size(); i++)
	{
		ownBoard.PrintBoard();

		std::string X, Y;
		bool isVertical;
		std::string userInput;

		std::cout << std::endl << "This is the " << gameRules.boatDatas[i].name << " |";
		for (size_t j = 0; j < gameRules.boatDatas[i].size; j++)
		{
			std::cout << gameRules.boatDatas[i].character << "|";
		}
		std::cout << std::endl;

		std::cout << "Enter X coord for " << gameRules.boatDatas[i].name << " position: ";
		std::cin >> X;

		std::cout << "Enter Y coord for " << gameRules.boatDatas[i].name << " position: ";
		std::cin >> Y;
	
		std::cout << "Enter V or H for the orientation of the boat: ";
		std::cin >> userInput;
		isVertical = userInput[0] == 'V';

		Coordinate c;
		c.SetBoardCoord(X, Y);

		Boat newBoat;
		newBoat.SetPosition(c);
		newBoat.SetIsVertical(isVertical);
		newBoat.SetSize(gameRules.boatDatas[i].size);
		newBoat.SetName(gameRules.boatDatas[i].name);
		if (ownBoard.IsBoatPositionValid(newBoat) == false)
		{
			std::cout << "Invalid Position!" << std::endl;
			i--;
			continue;
		}
		else
		{
			ownBoard.AddBoat(newBoat);
			Coordinate currentCoord{newBoat.GetPosition().x,newBoat.GetPosition().y};

			for (size_t j = 0; j < newBoat.GetSize(); j++)
			{
				ownBoard.GetTileAtCoord(currentCoord).SetTileValue(gameRules.boatDatas[i].character);
				if (newBoat.GetIsVertical() == true) 
				{
					currentCoord.y++;
				
				}
				else
				{
					currentCoord.x++;
				}
			}
		}
	}
}
