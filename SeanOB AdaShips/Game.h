#pragma once

#include "GameRules.h"
#include "Board.h"
#include "Boat.h"
#include "Turn.h"

class Game
{
private:
	bool isPlayerTurn = true;
	Board board1;
	Board board2;
	Turn* turn1;
	Turn* turn2;
	bool salvoMode = false;

public:
	bool closeGame = false;
	void SetUpGame(GameRules gameRules);
	void Menu();
	void Gameloop();
	void FinishGame();
};

