#include "ArithmeticFactory.h"

ArithmeticFactory::ArithmeticFactory(Line* line)
{
	std::map<std::string, size_t>::iterator assignIter = line->lvars.begin();
	std::map<std::string, size_t>::iterator opsIter;
	std::string assign;
	std::string firstVar;
	std::string secVar;
	std::string oper;
	if (line->llits.size() == 0)
	{
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->second < assignIter->second)
				assignIter = iter;
		}
		assign = assignIter->first + "var";
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->second > assignIter->second)
				assignIter = iter;
		}
		secVar = assignIter->first + "var";
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->first + "var" != assign && iter->first + "var" != secVar)
				assignIter = iter;
		}
		firstVar = assignIter->first + "var";
		for (auto iter = line->lops.begin(); iter != line->lops.end(); ++iter)
		{
			if (iter->first != "=")
				opsIter = iter;
		}
	}
	else if (line->llits.size() == 1)
	{
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->second < assignIter->second)
				assignIter = iter;
		}
		assign = assignIter->first + "var";
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->first + "var" != assignIter->first + "var")
				assignIter = iter;
		}
		firstVar = assignIter->first + "var";
		secVar = line->llits.begin()->first;
		for (auto iter = line->lops.begin(); iter != line->lops.end(); ++iter)
		{
			if (iter->first != "=")
				opsIter = iter;
		}
	}
	else if (line->llits.size() == 2)
	{
		for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
		{
			if (iter->second < assignIter->second)
				assignIter = iter;
		}
		assign = assignIter->first + "var";
		assignIter = line->llits.begin();
		for (auto iter = line->llits.begin(); iter != line->llits.end(); ++iter)
		{
			if (iter->second < assignIter->second)
				assignIter = iter;
		}
		firstVar = assignIter->first;
		for (auto iter = line->llits.begin(); iter != line->llits.end(); ++iter)
		{
			if (iter->first != assignIter->first)
			{
				assignIter = iter;
				break;
			}
		}
		secVar = assignIter->first;
		for (auto iter = line->lops.begin(); iter != line->lops.end(); ++iter)
		{
			if (iter->first != "=")
				opsIter = iter;
		}

	}
	oper = opsIter->first;
	if (oper == "+")
		arith = new Addition(firstVar, secVar, assign);
	else if (oper == "-")
		arith = new Subtraction(firstVar, secVar, assign);
	else if (oper == "*")
		arith = new Multiplication(firstVar, secVar, assign);
	else if (oper == "/")
		arith = new Division(firstVar, secVar, assign);
}
