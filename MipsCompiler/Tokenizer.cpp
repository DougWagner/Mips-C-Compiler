#include "Tokenizer.h"

Tokenizer::Tokenizer(std::vector<std::string> fileVec, FileStructure fstruc)
{
	for (int i = 0; i < fileVec.size(); i++)
	{
		lines.push_back(tokenizeLine(i, fileVec[i], fstruc));
	}
}

Line* Tokenizer::tokenizeLine(int linenum, std::string linetext, FileStructure fstruc)
{
	Line* line = new Line;
	auto tokenMaps = findTokens(linetext);
	line->lnum = linenum;
	line->lblock = fstruc.findBlockContainingLine(linenum);
	line->lkeys = tokenMaps[0];
	line->lvars = tokenMaps[1];
	line->lops = tokenMaps[2];
	line->llits = tokenMaps[3];
	line->ltype = findType(line);
	return line;
}

/*	vector index 0 = lkeys
 *	vector index 1 = lvars
 *	vector index 2 = lops
 *	vector index 3 = llits
 */
std::vector<std::map<size_t, std::string>> Tokenizer::findTokens(std::string line)
{
	std::vector<std::map<size_t, std::string>> vec;
	std::map<size_t, std::string> lkeys;
	std::map<size_t, std::string> lvars;
	std::map<size_t, std::string> lops;
	std::map<size_t, std::string> llits;
	std::string words = seperateWords(line);
	std::vector<std::string> keys = getKeys(words);
	std::vector<std::string> vars = getVars(words);
	std::vector<std::string> ops = getOps(line);
	std::vector<std::string> lits = getLits(words);
	size_t pos = 0;
	for (int i = 0; i < keys.size(); i++)
	{
		pos = line.find(keys[i], pos);
		lkeys.insert(std::pair<size_t, std::string>(pos++, keys[i]));
	}
	pos = 0;
	for (int i = 0; i < vars.size(); i++)
	{
		pos = line.find(vars[i], pos);
		lvars.insert(std::pair<size_t, std::string>(pos++, vars[i]));
	}
	pos = 0;
	for (int i = 0; i < ops.size(); i++)
	{
		pos = line.find(ops[i], pos);
		lops.insert(std::pair<size_t, std::string>(pos++, ops[i]));
	}
	pos = 0;
	for (int i = 0; i < lits.size(); i++)
	{
		pos = line.find(lits[i], pos);
		llits.insert(std::pair<size_t, std::string>(pos++, lits[i]));
	}
	vec.push_back(lkeys);
	vec.push_back(lvars);
	vec.push_back(lops);
	vec.push_back(llits);
	return vec;
}

std::string Tokenizer::seperateWords(std::string line)
{
	std::string newline;
	std::string::iterator it = line.begin();
	while (it != line.end())
	{
		if ((*it >= '0' && *it <= '9') || (*it >= 'A' && *it <= 'Z') || (*it >= 'a' && *it <= 'z') || *it == ' ' || *it == '_')
		{
			newline += *it;
			it++;
		}
		else
		{
			newline += ' ';
			it++;
		}
	}
	return newline;
}