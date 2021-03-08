#include "Game.h"

void Game::SetUpGame(GameRules gameRules)
{

	PlayerBoard.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);
	AiBoard.setUpBoard(gameRules.boardWidth, gameRules.boardHeight);

}
