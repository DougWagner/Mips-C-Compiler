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

enum LineType { decl, arith, assign, cond, loop };

struct Line
{
	int lnum;
	Block* lblock;
	std::vector<LineType> ltype;
	std::map<std::string, size_t> lkeys;
	std::map<std::string, size_t> lvars;
	std::map<std::string, size_t> lops;
	std::map<std::string, size_t> llits;
};

class Tokenizer
{
private:
	std::vector<Line*> lines;
	std::unordered_set<std::string> keywords;
protected:
	Line* tokenizeLine(int, std::string, FileStructure);
	std::vector<std::map<std::string, size_t>> findTokens(std::string);
	std::vector<LineType> findType(Line*);
	std::string seperateWords(std::string);
	std::vector<std::string> getKeys(std::string);
	std::vector<std::string> getVars(std::string);
	std::vector<std::string> getOps(std::string);
	std::vector<std::string> getLits(std::string);
	std::vector<std::string> getWords(std::string);
	void buildKeywords();
public:
	Tokenizer() {}
	Tokenizer(std::vector<std::string>, FileStructure);
	Line* getLineData(int);
};