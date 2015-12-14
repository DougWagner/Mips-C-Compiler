#include "DeclarationFactory.h"

DeclarationFactory::DeclarationFactory(Line* line)
{
	std::map<std::string, size_t>::iterator nameIter = line->lvars.begin();

	for (auto iter = line->lvars.begin();  iter != line->lvars.end(); ++iter)
	{
		if (iter->second < nameIter->second)
			nameIter = iter;
	}
	std::string myString = nameIter->first;
	intDec = IntDeclaration(myString);
}

