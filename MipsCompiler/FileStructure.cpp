#include "FileStructure.h"

FileStructure::FileStructure(std::vector<std::string> fileVect)
{
	root = createBlock(0, fileVect.size() - 1, 0, fileVect[fileVect.size() - 1].length(), 0); // parent is 0 because root
	unsigned int i = 0;
	size_t x = 0;
	fillBlockTree(&i, &x, root, fileVect);
	//printStructure(root, fileVect);
	//printBlock(findBlockContainingLine(17), fileVect);
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

void FileStructure::fillBlockTree(unsigned int* idx, size_t* lidx, Block* block, std::vector<std::string> vec)
{
	/*
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
	*/
	for (*idx; *idx < vec.size(); *idx += 1)
	{
		*lidx = vec[*idx].find("{", *lidx);
		if (*lidx != std::string::npos)
		{
			Block* newBlock = createBlock(*idx, *lidx, block);
			block->children.push_back(newBlock);
			*lidx += 1;
			fillBlockTree(idx, lidx, newBlock, vec);
			*lidx += 1;
			//lidx++;
		}
		if(*lidx == std::string::npos)
		{
			*lidx = 0;
		}
		*lidx = vec[*idx].find("}", *lidx);
		if (*lidx != std::string::npos)
		{
			block->bottom = *idx;
			block->bottomPos = *lidx;
			break;
		}
		*lidx = 0;
	}
}

Block* FileStructure::findBlockContainingLine(int lnum)
{
	Block* current = root;
	for (int i = 0; i < current->children.size(); i++)
	{
		if (lnum >= current->children[i]->top && lnum < current->children[i]->bottom)
		{
			return findBlockContainingLine(lnum, current->children[i]);
		}
	}
	return current;
}

Block* FileStructure::findBlockContainingLine(int lnum, Block* current)
{
	for (int i = 0; i < current->children.size(); i++)
	{
		if (lnum >= current->children[i]->top && lnum < current->children[i]->bottom)
		{
			return findBlockContainingLine(lnum, current->children[i]);
		}
	}
	return current;
}

void FileStructure::printStructure(Block* block, std::vector<std::string> vec)
{
	for (int i = 0; i < block->children.size(); i++)
	{
		printStructure(block->children[i], vec);
	}
	std::cout << "Start Block" << std::endl;
	for (int i = block->top; i <= block->bottom; i++)
	{
		std::cout << vec[i] << std::endl;
	}
	std::cout << std::endl;
}

void FileStructure::printBlock(Block* block, std::vector<std::string> vec)
{
	for (int i = block->top; i <= block->bottom; i++)
	{
		std::cout << vec[i] << std::endl;
	}
}