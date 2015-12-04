#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
struct Block
{
	Block* parent;
	int top, bottom;
	size_t topPos, bottomPos;
	std::vector<Block*> children;
};

class FileStructure
{
private:
	Block* root;
protected:
	Block* createBlock(int, int, size_t, size_t, Block*);
	Block* createBlock(int, size_t, Block*);
	void fillBlockTree(unsigned int*, size_t, Block*, std::vector<std::string>);
public:
	FileStructure() {}
	FileStructure(std::vector<std::string>);
	void printStructure();
};