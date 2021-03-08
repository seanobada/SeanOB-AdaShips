#include <iostream>
#include <vector>
#include <fstream>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <cstdlib>
//#include "tile.h"
#include "FileReader.h"

struct worldParameters
{
	int height;
	int width;
};

struct boatParameters
{
	std::string name;
	int size;
};

class BattleShips
{
private:

	//int worldWidth_;
	//int worldHeight_;

	std::vector<boatParameters> boats;

protected:

public:

	void setUpBoard()
	{
		// sets up board to predefined parameters in the config file
		std::vector<std::vector<char>> board;
		int row = 10, col = 10;
		for (int x = 0; x < row; x++) {
			std::vector<char> columns;
			board.push_back(columns);
			for (int y = 0; y < col; y++)
			{
				board[x].push_back('~');
			}
		}
		for (int x = 0, cnt = 1; x < row; x++)
		{
			for (int y = 0; y < col; y++)
			{
				std::cout << board[x][y] << "|";
			}
			std::cout << std::endl;
		}
	}


	void menu()
	{
		bool doRun = true;
		int menuInput;
		std::cout << std::endl;
		std::cout << "Welcome to Adaship!" << std::endl;
		std::cout << "1: Gamemode Selection" << std::endl;
		std::cout << "0: Quit" << std::endl;
		std::cout << "Enter Choice:  ";
		std::cin >> menuInput;
		while (doRun == true); {
			switch (menuInput)
			{
			case 1: //playGame(); break;
			case 0: //gameQuit(); break;
			default:
				std::cout << menuInput << "is an Invalid Input - Please try again.";
					break;
			}
		} 
	}
};



void playGame()
{

}

int main()
{		
	std::string fileName = "adaship_config.ini";
	FileReader::Instance().ReadFile(fileName);

	BattleShips bs;
	//bs.menu();
	bs.setUpBoard();
	
	
}

