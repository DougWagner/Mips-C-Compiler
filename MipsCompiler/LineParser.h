#pragma once
#include "MipsCompiler.h"
class LineParser
{
private:
	std::ifstream* file;
	std::string currentLine;
public:
	LineParser(std::ifstream&);
	void readFile();
};