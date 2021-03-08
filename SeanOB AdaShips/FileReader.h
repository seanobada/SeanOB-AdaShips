#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>

class FileReader
{
private:

	FileReader() {};

	std::string filename;
	std::ifstream configFile;
	std::string line = "";

	std::string control = "";
	std::string value = "";

	std::string boatname = "";
	std::string boatsize = "";

public:

	static FileReader& Instance()
	{
		static FileReader instance;
		return instance;
	}

	void ReadFile(std::string filename);
	std::string split(std::string source, char delimiter, int index);
	std::string trim(std::string source);

};