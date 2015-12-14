#include "VariableAssign.h"

IntAssign::IntAssign(std::string vName, std::string vValue)
{
	varName = vName;
	varValue = vValue;
}
std::string IntAssign::convertToMips()
{
	return "hello";
}
