#include "VariableDeclarations.h"

IntDeclaration::IntDeclaration(std::string vName, std::string vType)
{
	varName = vName;
	varType = vType;

}
IntDeclaration::IntDeclaration(std::string vName, std::string vType,
	std::string vValue)
{
	varName = vName;
	varType = vType;
	varValue = vValue;
}
void IntDeclaration::convertToMips()
{
	std::string converted = ("%s \t\t .word %s", varName, varValue);
}