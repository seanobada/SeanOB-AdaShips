#include <iostream>
#include <chrono>
#include <thread>
#include <random>
#include <vector>

#include "AiTurn.h"
#include "FileReader.h"

void AiTurn::DoTurn(Board& opponentBoard, int salvoCount)
{
	std::cout << "Ai Thinking..." << std::endl;
	
	std::vector<Coordinate> targetCoords;
	Coordinate c;
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
			c.x = (rand() % opponentBoard.GetWidth());
			c.y = (rand() % opponentBoard.GetHeight());
			isValidInput = true;

			if (c.x > opponentBoard.GetWidth() - 1 || c.y > opponentBoard.GetHeight() - 1 || c.x < 0 || c.y < 0)
			{
				isValidInput = false;
				continue;
			}
			if (opponentBoard.GetTileAtCoord(c).GetIsDamaged() == true)
			{
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
				std::cout << "Destroyed " << hitBoat->GetName() << "!" << std::endl;
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

void AiTurn::DoBoatPlacement(Board& ownBoard, GameRules gameRules)
{
	
	for (size_t i = 0; i < gameRules.boatDatas.size(); i++)
	{
		int X,Y;
		bool isVertical;

		X = (rand() % ownBoard.GetWidth());
		Y = (rand() % ownBoard.GetHeight());
		isVertical = (rand() % 2);

		Coordinate c{ X,Y };

		Boat newBoat;
		newBoat.SetPosition(c);
		newBoat.SetIsVertical(isVertical);
		newBoat.SetSize(gameRules.boatDatas[i].size);
		newBoat.SetName(gameRules.boatDatas[i].name);
		if (ownBoard.IsBoatPositionValid(newBoat) == false)
		{
			i--;
			continue;
		}
		else
		{
			ownBoard.AddBoat(newBoat);
			Coordinate currentCoord{ newBoat.GetPosition().x,newBoat.GetPosition().y };

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


