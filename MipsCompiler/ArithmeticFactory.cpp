#include "ArithmeticFactory.h"
/*
ArithmeticFactory::ArithmeticFactory(Line* line)
{
	std::map<std::string, size_t>::iterator assignIter = line->lvars.begin();
	std::map<std::string, size_t>::iterator opsIter;
	std::string assign;
	std::string firstVar;
	std::string secVar;
	std::string oper;
	for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
	{
		if (iter->second < assignIter->second)
			assignIter = iter;
	}
	assign = assignIter->first;
	for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
	{
		if (iter->second > assignIter->second)
			assignIter = iter;
	}
	secVar = assignIter->first;
	for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
	{
		if (iter->first != assignIter->first)
			assignIter = iter;
	}
	firstVar = assignIter->first;
	for (auto iter = line->lops.begin(); iter != line->lops.end(); ++iter)
	{
		if (iter->first != "=")
			opsIter = iter;
	}
	oper = opsIter->first;
	if (oper == "+")
		arith = new Addition(firstVar, secVar, assign);
}
*/