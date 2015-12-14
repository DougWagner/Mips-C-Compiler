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
#include "Tokenizer.h"
#include "ArithmeticFactory.h"
#include "LineHandler.h"
//#include "ArithmeticFactory.h"
//#include "Arithmetic.h"

class MipsCompiler
{
private:
	std::vector<std::string> file;
	FileStructure structure;
	Tokenizer tokens;
	LineHandler handler;
	Output out;
	std::string outfile;
protected:
	void initializeFile(std::string);
	void analyzeStructure();
	void tokenize();
	void handleLines();
public:
	MipsCompiler(std::string, std::string);
	void printFile();
	void printOutput();
};
