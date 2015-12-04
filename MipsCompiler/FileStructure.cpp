#include "FileStructure.h"

FileStructure::FileStructure(std::vector<std::string> fileVect)
{
	root = createBlock(0, fileVect.size() - 1, 0, fileVect[fileVect.size() - 1].length(), 0); // parent is 0 because root
	unsigned int i = 0;
	fillBlockTree(&i, 0, root, fileVect);
}

Block* FileStructure::createBlock(int x, int y, size_t xPos, size_t yPos, Block* p)
{
	Block* b = new Block;
	b->top = x;
	b->bottom = y;
	b->topPos = xPos;
	b->bottomPos = yPos;
	b->parent = p;
	return b;	
}

Block* FileStructure::createBlock(int x, size_t xPos, Block* p)
{
	Block* b = new Block;
	b->top = x;
	b->topPos = xPos;
	b->parent = p;
	return b;
}

void FileStructure::fillBlockTree(unsigned int* idx, size_t lidx, Block* block, std::vector<std::string> vec)
{
	for (*idx; *idx < vec.size(); *idx += 1)
	{
		auto x = vec[*idx].find("{", lidx);
		if (x != std::string::npos)
		{
			Block* newBlock = createBlock(*idx, x, block);
			block->children.push_back(newBlock);
			fillBlockTree(idx, x + 1, newBlock, vec);
			lidx++;
		}
		auto y = vec[*idx].find("}", lidx);
		if (y != std::string::npos)
		{
			block->bottom = *idx;
			block->bottomPos = y;
			break;
		}
		lidx = 0;
	}
}