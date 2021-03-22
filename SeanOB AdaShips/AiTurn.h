#pragma once
#include "Turn.h"
#include "GameRules.h"
class AiTurn:public Turn
{
	void DoTurn(Board& opponentBoard);
	void DoBoatPlacement(Board& ownBoard, GameRules gamerules);
};

