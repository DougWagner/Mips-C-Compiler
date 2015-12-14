#pragma once
#include "MipsCompiler.h"

class VariableAssign
{
public:
	VariableAssign();
	virtual std::string getVarName() = 0;
	virtual std::string getVarValue() = 0;
	virtual std::string convertToMips() = 0;

};

class IntAssign : private virtual VariableAssign
{
private:
	std::string varName, varValue;
public:
	IntAssign(std::string vName, std::string vValue);
	std::string getVarName() { return varName; }
	std::string getVarValue() { return varValue; }
	std::string convertToMips();
};