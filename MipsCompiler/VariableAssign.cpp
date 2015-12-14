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
	//std::string converted = ("%sli $t1, %s\n%sw $t1, %s", tabs, varValue,
	//	 tabs, varName);
	return ss.str();
}
