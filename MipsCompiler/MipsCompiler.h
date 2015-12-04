#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

#include "FileStructure.h"
#include "ArithmeticFactory.h"
//#include "Lineparser.h"
//#include "Lexer.h"
//#include "ArithmeticFactory.h"
//#include "Arithmetic.h"

class MipsCompiler
{
private:
	std::vector<std::string> file;
	FileStructure asdf;
protected:
	void initializeFile(std::string);
	void analyzeStructure();
public:
	MipsCompiler(std::string);
	void printFile();
};
