#include <iostream>

#include "PlayerTurn.h"


void PlayerTurn::DoTurn(Board& opponentBoard)
{

}

void PlayerTurn::DoBoatPlacement(Board& ownBoard, GameRules gameRules)
{
	for (size_t i = 0; i < gameRules.boatDatas.size(); i++)
	{
		ownBoard.PrintBoard();

		int X, Y;
		bool isVertical;
		std::string userInput;

		std::cout << std::endl << "This is the " << gameRules.boatDatas[i].name << " |";
		for (size_t j = 0; j < gameRules.boatDatas[i].size; j++)
		{
			std::cout << gameRules.boatDatas[i].character << "|";
		}
		std::cout << std::endl;

		std::cout << "Enter X coord for " << gameRules.boatDatas[i].name << " position: ";
		std::cin >> userInput;
		X = std::stoi(userInput);

		std::cout << "Enter Y coord for " << gameRules.boatDatas[i].name << " position: ";
		std::cin >> userInput;
		Y = std::stoi(userInput);

		std::cout << "Enter V or H for the orientation of the boat: ";
		std::cin >> userInput;
		isVertical = userInput[0] == 'V';

		
		


	}
}
