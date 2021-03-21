#include "FileReader.h"
#include "GameRules.h"

std::string FileReader::trim(std::string source)
{
	return source;
}

std::string FileReader::split(std::string source, char delimiter, int index)
{
	std::vector<std::string> results;
	std::stringstream s_stream(source); //create string stream from the string

	while (s_stream.good()) {
		std::string substr;
		getline(s_stream, substr, delimiter); //get first string by delimited
		results.push_back(trim(substr));
	}
	return results[index];
}

GameRules FileReader::ReadFile(std::string filename)
{
	GameRules gameRules;
	configFile.open(filename);
	while (!configFile.eof())
	{
		getline(configFile, line);
		if (line == "")
		{
			continue;
		}

		control = split(line, ':', 0);
		value = split(line, ':', 1);

		int boatsize = 0, boardWidth = 0, boardHeight = 0;

		if (control == "Board")
		{
			gameRules.boardWidth = std::stoi(split(value, 'x', 0));
			gameRules.boardHeight = std::stoi(split(value, 'x', 1));

		}
		if (control == "Boat")
		{
			BoatData bd{split(value, ',', 0), std::stoi(split(value, ',', 1)), split(value, ',', 2)[0] };
			gameRules.boatDatas.push_back(bd);
		}

	}
	configFile.close();
	return gameRules;
}


