#include "VariableDeclarations.h"

IntDeclaration::IntDeclaration(std::string vName, std::string vValue)
{
	varName = vName;
	varValue = vValue;

}
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
std::string initVar(std::string name, std::string value)
{
	std::string s1 = ("li $t0, %s\n", value);
	std::string s2 = ("sw $t0, %s\n", name);
	std::string converted = s1 + s2;
	return converted;
}