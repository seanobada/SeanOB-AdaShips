#pragma once
#include "Turn.h"
#include "GameRules.h"
class PlayerTurn:public Turn
{
public:
	void DoTurn(Board& opponentBoard);
	void DoBoatPlacement(Board& ownBoard, GameRules gamerules);
};

