#include "VariableDeclarations.h"

IntDeclaration::IntDeclaration(std::string vName)
{
	varName = vName;
	varValue = "0";
}
std::string IntDeclaration::convertToMips()
{
	std::string tabs = "\t\t\t";
	std::string converted = ("%s%s \t\t .word %s",tabs, varName, varValue);
	return converted;
}
