#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <sstream>
#include <unordered_set>
#include "Tokenizer.h"
//#include "MipsCompiler.h"

class VariableDeclartation
{

public:
	VariableDeclartation() {}
	virtual std::string getVarName() = 0;
	virtual std::string convertToMips() = 0;
};

class IntDeclaration : private virtual VariableDeclartation
{
private:
	std::string varName, varValue;
public:
	/*
		Standard initializer for var declarations.
		It takes two parameters.
		IntDeclaration(string Name, string value)
	*/
	IntDeclaration() {}
	IntDeclaration(std::string vName);
	std::string getVarName() override { return varName; }
	/*
		This converts C code to mips code 
		and adds it to the .data portion of
		the mips code.
	*/
	std::string convertToMips() override;
	/*
		This is for when a variable is later
		initialized. takes in two strings.
		initVar(string variableName, string value)
	*/
};