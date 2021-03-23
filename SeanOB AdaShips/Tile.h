#pragma once
// essentially a query for the tiles so that the game can say if the players move was a hit
class Tile
{
private:
	char tileValue = '~';
		//"D S C P B M" ~  X 
	bool isRevealed = true;
	bool isDamaged = false;
public:
	char GetTileValue();
	void SetTileValue(char newTileValue);
	bool GetIsRevealed();
	void SetIsRevealed(bool v);
	bool GetIsDamaged();
	void SetIsDamaged(bool isDamaged);
	

};

