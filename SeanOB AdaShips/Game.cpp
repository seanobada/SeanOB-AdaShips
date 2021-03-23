
#include <chrono>
#include <thread>

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
	std::cout << "4 : User vs Ai (Salvo mode)" << std::endl;
	std::cout << "5 : User vs User (Salvo mode)" << std::endl;
	std::cout << "6 : Ai vs Ai (Salvo mode)" << std::endl;
	std::cout << "0 : Quit" << std::endl;
	std::cout << "Enter a value to select Gamemode or (0) to quit: ";
	std::cin >> menuInput;
	switch (menuInput)
	{
    case 1: 
        turn1 = new PlayerTurn();
		std::cout << "Ai Thinking..." << std::endl;
        turn2 = new AiTurn();
        break;
    case 2:
        turn1 = new PlayerTurn();
        turn2 = new PlayerTurn();
        break;
    case 3:
		std::cout << "Ai Thinking..." << std::endl;
        turn1 = new AiTurn();
        turn2 = new AiTurn();
        break;
    case 4:
		salvoMode = true;
        turn1 = new PlayerTurn();
		std::cout << "Ai Thinking..." << std::endl;
        turn2 = new AiTurn();
        break;
    case 5:
		salvoMode = true;
        turn1 = new PlayerTurn();
		turn2 = new PlayerTurn();
        break;
    case 6:
		salvoMode = true;
		std::cout << "Ai Thinking..." << std::endl;
        turn1 = new AiTurn(); 
		turn2 = new AiTurn();
        break;
    case 0:
        closeGame = true;
        break;
	default:
		closeGame = true;
		break;
	}
}

void Game::Gameloop()
{
	board1.Unreveal();
	board2.Unreveal();
	int boatsLeft;
	while (true)
	{
		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Player 1 Turn" << std::endl;
		board2.PrintBoard();
		boatsLeft = salvoMode ? board2.BoatsRemaining() : 1;
		turn1->DoTurn(board2,boatsLeft);
		if (board2.BoatsRemaining() <= 0)
		{
			std::cout << "Player 1 Wins!" << std::endl;
			return;
		}

		std::this_thread::sleep_for(std::chrono::seconds(1));
		std::cout << "Player 2 Turn" << std::endl;
		board1.PrintBoard();
		boatsLeft = salvoMode ? board1.BoatsRemaining() : 1;
		turn2->DoTurn(board1, boatsLeft);
		if (board1.BoatsRemaining() <= 0)
		{
			std::cout << "Player 2 Wins!" << std::endl;
			return;
		}
	}
}

void Game::FinishGame()
{
	delete turn1;
	delete turn2;
}


