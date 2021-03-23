#include "Coordinate.h"
#include <iostream>

Coordinate::Coordinate(int newX, int newY) : x(newX), y(newY){}

Coordinate::Coordinate() : x(0), y(0) {}



std::string Coordinate::ToBoardCoord()
{
    std::string output = "";
    std::string xCoord = "";
    std::string yCoord = std::to_string(y + 1) ;
    int remainingX = x;

    if (remainingX == 0)
    {
        xCoord = (char)(remainingX + 65);
    }
    else
    {
        while (remainingX > 0)
        {
            int r = remainingX % 26;
            xCoord = (char)(r + 65) + xCoord;
            remainingX = (remainingX / 26) - 1;
            if (remainingX == 0)
            {
                xCoord = (char)(remainingX + 65) + xCoord;
            }
        }
    }
    output = xCoord + ',' + yCoord;
    return output;
}

void Coordinate::SetBoardCoord(std::string x, std::string y)
{
    this->y = std::stoi(y) - 1;

    int total = 0;
    for (int i = (x.length()-1); i >= 0; i--)
    {
        int decimal = x[i] - 'A' + 1;
        int holdingValue = decimal* pow(26, i);
        total += holdingValue;
    }
    this->x = total - 1;
}
