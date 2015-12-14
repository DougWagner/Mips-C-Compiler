#include "LineHandler.h"

LineHandler::LineHandler(Tokenizer tokens)
{
	for (int i = 0; i < tokens.getSize(); i++)
	{
		Line* current = tokens.getLineData(i);
		for (auto x : current->ltype)
		{
			sendToFactory(current, x);
		}
	}
}

void LineHandler::sendToFactory(Line* line, LineType type)
{
	if (type == decl)
	{
		declFact = DeclarationFactory(line);
		auto x = declFact.getIntDec();
		
	}
	else if (type == arith)
	{
		arithFact = ArithmeticFactory(line);
	}
	else if (type == assign)
	{
		assignFact = AssignmentFactory(line);
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