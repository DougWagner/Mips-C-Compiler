#include "LineHandler.h"

LineHandler::LineHandler(Tokenizer tokens, FileStructure structure)
{
	out = Output();
	handleBlock(tokens, structure.findBlockContainingLine(0), structure); // send to block handler with root block
	/*
	for (int i = 0; i < tokens.getSize(); i++)
	{
		Line* current = tokens.getLineData(i);
		for (auto x : current->ltype)
		{
			sendToFactory(current, x);
		}
		//out.print();
	}
	//out.print();
	*/

}

void LineHandler::handleBlock(Tokenizer tokens, Block* block, FileStructure structure)
{
	for (unsigned int i = 0; i < block->children.size(); i++)
	{
		handleBlock(tokens, block->children[i], structure);
	}
	for (int i = block->top; i <= block->bottom; i++)
	{
		if (structure.findBlockContainingLine(i) != block)
		{
			continue;
		}
		Line* current = tokens.getLineData(i);
		for (auto x : current->ltype)
		{
			std::cout << current->lnum << " sent to factory" << std::endl;
		}
	}
}

void LineHandler::sendToFactory(Line* line, LineType type)
{
	if (type == decl)
	{
		declFact = DeclarationFactory(line);
		auto x = declFact.getIntDec();
		out.insertData(x->convertToMips());
	}
	else if (type == arith)
	{
		arithFact = ArithmeticFactory(line);
		auto x = arithFact.getArith();
		out.insertCode(x->arithmeticOp());
	}
	else if (type == assign)
	{
		assignFact = AssignmentFactory(line);
		auto x = assignFact.getIntAssign();
		out.insertCode(x->convertToMips());
	}
	/*
	for (auto x : line->ltype)
	{
		if (x == decl)
		{
			declFact = DeclarationFactory(line);
		}
		else if (x == arith)
		{
			arithFact = ArithmeticFactory(line);
		}
		else if (x == assign)
		{

		}
		else if (x == cond)
		{

		}
		else if (x == loop)
		{

		}
	}
	*/
}

Output LineHandler::getOutput()
{
	return out;
}