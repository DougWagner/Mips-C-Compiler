#include "MipsCompiler.h"

LineParser::LineParser(std::ifstream& infile)
{
	file = &infile;
}

void LineParser::readFile()
{
	while (!file->eof())
	{
		std::getline(*file, currentLine);
		Lexer lex = Lexer(currentLine);
	}
}


