#include "Boat.h"

void Boat::SetPosition(Coordinate coord)
{
	position = coord;
}

Coordinate Boat::GetPosition()
{
	return position;
}

bool Boat::GetIsDestroyed()
{
	return isDestroyed;
}

void Boat::SetIsVertical(bool value)
{
	isVertical = value;
}

bool Boat::GetIsVertical()
{
	return isVertical;
}

int Boat::GetSize()
{
	return size;
}
