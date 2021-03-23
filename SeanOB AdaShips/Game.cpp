#include "Game.h"
#include "GameRules.h"
#include "Board.h"
#include "Boat.h"
#include "Turn.h"
#include "PlayerTurn.h"
#include "AiTurn.h"

void Game::SetUpGame(GameRules gameRules)
{
	board1.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);
	board2.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);
	turn1->DoBoatPlacement(board1, gameRules);
	turn2->DoBoatPlacement(board2, gameRules);
	
}

void Game::Menu()
{
	int menuInput;
	std::cout << "Welcome to AdaShips! By Sean O'Brien" << std::endl;
	std::cout << "1 : User vs Ai" << std::endl;
	std::cout << "2 : User vs User" << std::endl;
	std::cout << "3 : Ai vs Ai" << std::endl;
	std::cout << "0 : Quit" << std::endl;
	std::cout << "Enter a value to select Gamemode or (0) to quit:";
	std::cin >> menuInput;
	if (menuInput == 1)
	{
		turn1 = new PlayerTurn();
		turn2 = new AiTurn();
		// Gameloop();
	}
	if (menuInput == 2)
	{
		turn1 = new PlayerTurn();
		turn2 = new PlayerTurn();
		// Gameloop();
	}
	if (menuInput == 3)
	{
		turn1 = new AiTurn();
		turn2 = new AiTurn();
		// Gameloop();
	}
	if (menuInput == 0)
	{
		closeGame = true;
	}
}

void Game::Gameloop()
{
	while (true)
	{
		board2.PrintBoard();
		turn1->DoTurn(board2);
		/*board1.PrintBoard();
		turn2->DoTurn(board1);*/
	}
}

void Game::FinishGame()
{
	delete turn1;
	delete turn2;
}


