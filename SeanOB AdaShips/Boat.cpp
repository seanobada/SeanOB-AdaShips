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

void Boat::SetSize(int size)
{
	this->size = size;
}

int Boat::GetSize()
{
	return size;
}

void Boat::SetName(std::string name)
{
	this->name = name;
}

std::string Boat::GetName()
{
	return name;
}
