#pragma once
// essentially a query for the tiles so that the game can say if the players move was a hit
class Tile
{
private:
	char tileValue = '~';
		//"D S C P B M" ~ H X 
	bool isRevealed = true;
public:
	char GetTileValue();
	void SetTileValue(char newTileValue);
	bool GetIsRevealed();

};

