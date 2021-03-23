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

void Tile::SetIsRevealed(bool v)
{
	isRevealed = v;
}

bool Tile::GetIsDamaged()
{
	return isDamaged;
}

void Tile::SetIsDamaged(bool isDamaged)
{
	this->isDamaged = isDamaged;
}
