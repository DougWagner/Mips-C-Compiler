#pragma once
#include "MipsCompiler.h"
class Lexer
{
private:
	std::unordered_set<std::string> cReservedKeywords;
	std::vector<std::string> variables;
	std::vector<std::string> keywords;
	std::vector<std::string> operators;
	std::string currentLine;
	void initializeReservedKeys();
	void buildVariables();
	void buildKeywords();
	void buildOperators();
public:
	Lexer(std::string);
	std::vector<std::string> getVariables();
	std::vector<std::string> getKeywords();
	std::vector<std::string> operators();
};