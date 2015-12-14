#include "AssignmentFactory.h"
AssignmentFactory::AssignmentFactory(Line* line)
{
	std::map<std::string, size_t>::iterator nameIter = line->lvars.begin();
	std::map<std::string, size_t>::iterator valIter = line->llits.begin();
	for (auto iter = line->lvars.begin(); iter != line->lvars.end(); ++iter)
	{
		if (iter->second < nameIter->second)
			nameIter = iter;
	}
	for (auto iter = line->llits.begin(); iter != line->llits.end(); ++iter)
	{
		if (iter->second < valIter->second)
			valIter = iter;
	}
	intAssign = new IntAssign(nameIter->first, valIter->first);
}