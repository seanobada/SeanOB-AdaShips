#include "FileReader.h"

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

void FileReader::ReadFile(std::string filename)
{
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
			boardWidth = std::stoi(split(value, 'x', 0));
			boardHeight = std::stoi(split(value, 'x', 1));
			//std::cout << " - Board size is : " << /*split(value, 'x', 0) << split(*/value/*, 'x', 1)*/;
			//std::cout << boardHeight << boardWidth;
		}
		if (control == "Boat")
		{
			boatname = split(value, ',', 0);
			boatsize = std::stoi(split(value, ',', 1));
			//std::cout << boatsize;

			//	addBoat(boatname, boatsize);
			//std::cout << "\nfound a boat: " << boatname << ", size: " << boatsize << std::endl;
		}

	}
	configFile.close();
}


