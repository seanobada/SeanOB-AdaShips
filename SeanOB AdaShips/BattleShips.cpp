#include <iostream>

#include <sstream>
#include <cstdlib>
#include <string>


//#include "tile.h"
#include "FileReader.h"
#include "Board.h"
#include "GameRules.h"



int main()
{		
	std::string fileName = "adaship_config.ini";

	GameRules gameRules = FileReader::Instance().ReadFile(fileName);
	//for (size_t i = 0; i < gameRules.boatDatas.size(); i++)
	//{
	//	std::cout << gameRules.boatDatas[i].name;
	//	std::cout << gameRules.boatDatas[i].size << std::endl;
	//}

	
	
	

}

