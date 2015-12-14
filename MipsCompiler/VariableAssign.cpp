#include "VariableAssign.h"

IntAssign::IntAssign(std::string vName, std::string vValue)
{
	varName = vName;
	varValue = vValue;
}
std::string IntAssign::convertToMips()
{
	std::string tabs = "\t\t\t";
	std::stringstream ss;
	ss << "\t\tli, $t1, " << varValue << std::endl << "\t\tsw $t1, " << varName << std::endl;
	return ss.str();
}
