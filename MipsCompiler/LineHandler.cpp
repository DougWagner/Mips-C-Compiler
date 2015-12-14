#include "LineHandler.h"

LineHandler::LineHandler(Tokenizer tokens)
{
	for (int i = 0; i < tokens.getSize(); i++)
	{
		Line* current = tokens.getLineData(i);
		sendToFactory(current);
	}
}

void LineHandler::sendToFactory(Line* line)
{
	for (auto x : line->ltype)
	{
		if (x == decl)
		{
			declFact = DeclarationFactory(line);
		}
		/*
		else if (x == arith)
		{
			arithFact = ArithmeticFactory(line);
		}
		/*
		else if (x == assign)
		{

		}
		else if (x == cond)
		{

		}
		else if (x == loop)
		{

		}
		*/
	}
}