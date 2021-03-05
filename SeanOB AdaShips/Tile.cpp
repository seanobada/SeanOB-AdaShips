#include "Tile.h"

char Tile::GetTileValue()
{
	return tileValue;
}

void Tile::SetTileValue(char newTileValue)
{
	tileValue = newTileValue;
}

bool Tile::GetIsRevealed()
{
	
	return isRevealed;
}
