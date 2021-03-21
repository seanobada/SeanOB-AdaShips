#include "Game.h"
#include "GameRules.h"
#include "Board.h"
#include "Boat.h"

void Game::SetUpGame(GameRules gameRules)
{
	PlayerBoard.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);
	AiBoard.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);
	for (size_t i = 0; i < gameRules.boatDatas.size(); i++)
	{
		PlayerBoard.PrintBoard();
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
		
		std::cout << "Enter Y coord for " << gameRules.boatDatas[i].name << " position: ";
		std::cin >> userInput;
		std::cout << "Enter V or H for the orientation of the boat: ";
		std::cin >> userInput;

	}
}


