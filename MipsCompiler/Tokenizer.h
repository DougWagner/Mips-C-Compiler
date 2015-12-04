#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_set>
#include "FileStructure.h"
/*
class Line
{
public:
	
	
};
*/

enum LineType { decl, arith, assign, cond };

struct Line
{
	int lnum;
	Block* lblock;
	std::vector<LineType> ltype;
	std::map<size_t, std::string> lkeys;
	std::map<size_t, std::string> lvars;
	std::map<size_t, std::string> lops;
	std::map<size_t, std::string> llits;
};

class Tokenizer
{
private:
	std::vector<Line*> lines;
protected:
	Line* tokenizeLine(int, std::string, FileStructure);
	std::vector<std::map<size_t, std::string>> findTokens(std::string);
	std::vector<LineType> findType(Line*);
	std::string seperateWords(std::string);
	std::vector<std::string> getKeys(std::string);
	std::vector<std::string> getVars(std::string);
	std::vector<std::string> getOps(std::string);
	std::vector<std::string> getLits(std::string);
public:
	Tokenizer() {}
	Tokenizer(std::vector<std::string>, FileStructure);
};