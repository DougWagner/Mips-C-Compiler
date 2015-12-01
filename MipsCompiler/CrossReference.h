#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <unordered_set>
#include <unordered_map>
#include <map>
class CrossReference
{
private:
	// Variables
	std::unordered_set<std::string> keywords;
	std::unordered_map<std::string, std::vector<int>> varNames;
	std::map<std::string, std::vector<int>> sortedNames;

	// Functions
	void readFile(std::ifstream&);
	void parseLine(std::string, int);
	std::string seperateWords(std::string);
	std::vector<std::string> getWords(std::string);
	std::string checkQuotes(std::string);
	std::string checkComments(std::string);
	std::pair<std::string, bool> checkCommentBlocks(std::string, bool);
	void sortMap();
	void buildKeywords();
	bool fileExists(std::string);

public:
	// Constructor
	CrossReference(std::string);

	// Print Functions
	void printResultsCmdLine();
	void printResultsToFile(std::string);
};