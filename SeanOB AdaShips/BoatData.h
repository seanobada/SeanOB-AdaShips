#pragma once
#include <string>
struct BoatData
{
	BoatData(std::string newName, int newSize, char newCharacter);
	std::string name;
	int size;
	char character;
};

