#pragma once

#include "GameRules.h"
#include "Board.h"
#include "Boat.h"


class Game
{
private:
	bool isPlayerTurn = true;
	Board PlayerBoard;
	Board AiBoard;
public:
	void SetUpGame(GameRules gameRules);

};

