#pragma once
#include "Turn.h"
#include "GameRules.h"
class PlayerTurn:public Turn
{
public:
	void DoTurn(Board& opponentBoard, int salvoCount = 1);
	void DoBoatPlacement(Board& ownBoard, GameRules gamerules);
};

