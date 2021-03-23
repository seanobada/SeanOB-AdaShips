#include <iostream>

#include "PlayerTurn.h"
#include "Tile.h"


void PlayerTurn::DoTurn(Board& opponentBoard)
{
	//enter coord value, test coord value as valid(not hit before), response, change tile value depending on response 
	Coordinate c;
	std::string x, y;
	bool isValidInput = true;
	do
	{
		isValidInput = true;
		std::cout << "Enter X coord for your attack: ";
		std::cin >> x;

		std::cout << "Enter Y coord for your attack: ";
		std::cin >> y;

		c.SetBoardCoord(x, y);

		if (c.x > opponentBoard.GetWidth() - 1 || c.y > opponentBoard.GetHeight() - 1 || c.x < 0 || c.y < 0)
		{
			std::cout << "Invalid input! Try again." << std::endl;
			isValidInput = false;
			continue;
		}
		if (opponentBoard.GetTileAtCoord(c).GetIsDamaged() == true)
		{
			std::cout << "Invalid input! Try again." << std::endl;
			isValidInput = false;
		}
	} while (isValidInput == false);

	opponentBoard.GetTileAtCoord(c).SetIsDamaged(true);
	opponentBoard.GetTileAtCoord(c).SetTileValue('X');
	opponentBoard.GetTileAtCoord(c).SetIsRevealed(true);


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
//TODO AI Positioning
//TODO Targeting System for AI(logic + error handling) and Player(logic + error handling) + isDestroyed Condition Checking
//TODO Win Conditions
//TODO Slav mode