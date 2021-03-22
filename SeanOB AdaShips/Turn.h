#pragma once
#include "GameRules.h"
#include "Board.h"
class Turn
{
public:
	virtual void DoTurn(Board& opponentBoard);
	virtual void DoBoatPlacement(Board& ownBoard, GameRules gamerules);
};

