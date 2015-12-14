#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include <list>

class Output
{
private:
	std::list<std::string> output;
	int dataloc, textloc, globlloc, mainloc, exitloc;
public:
	Output();
	void insertData(std::string);
	void insertCode(std::string);
	void printToFile(std::string);
};