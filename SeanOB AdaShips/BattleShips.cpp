#include <iostream>

#include <sstream>
#include <cstdlib>
#include <string>


//#include "tile.h"
#include "FileReader.h"
#include "Board.h"
#include "GameRules.h"
#include "Game.h"
#include "Coordinate.h"


int main()
{		
	std::string fileName = "adaship_config.ini";

	GameRules gameRules = FileReader::Instance().ReadFile(fileName);


	Game game;
	game.Menu();
	if (game.closeGame == false)
	{
		game.SetUpGame(gameRules);
		game.Gameloop();
	}
	game.FinishGame();
	exit(0);
}

