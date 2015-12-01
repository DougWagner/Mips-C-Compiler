#pragma once
#include "MipsCompiler.h"

class VariableDeclartation
{
public:
	VariableDeclartation();
	virtual std::string getVarName() = 0;
	virtual std::string getVarValue() = 0;
	virtual void convertToMips() = 0;
};

class IntDeclaration : private virtual VariableDeclartation
{
private:
	std::string varName, varType, varValue;
public:
	IntDeclaration(std::string vName, std::string vType);
	IntDeclaration(std::string vName, std::string vType, std::string vValue);
	std::string getVarName() { return varName; }
	void convertToMips();

};