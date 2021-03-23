#pragma once
#include "Turn.h"
#include "GameRules.h"
class AiTurn:public Turn
{
	void DoTurn(Board& opponentBoard, int salvoCount = 1);
	void DoBoatPlacement(Board& ownBoard, GameRules gamerules);
};

