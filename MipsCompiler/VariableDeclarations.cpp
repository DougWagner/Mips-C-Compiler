#include "VariableDeclarations.h"

IntDeclaration::IntDeclaration(std::string vName)
{
	varName = vName;
	varValue = "0";
}
std::string IntDeclaration::convertToMips()
{
	std::string converted = ("%s \t\t .word %s", varName, varValue);
	return converted;
}
