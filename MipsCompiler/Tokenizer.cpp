#include "Tokenizer.h"

Tokenizer::Tokenizer(std::vector<std::string> fileVec, FileStructure fstruc)
{
	size = fileVec.size();
	buildKeywords();
	for (unsigned int i = 0; i < fileVec.size(); i++)
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
std::vector<std::map<std::string, size_t>> Tokenizer::findTokens(std::string line)
{
	std::vector<std::map<std::string, size_t>> vec;
	std::map<std::string, size_t> lkeys;
	std::map<std::string, size_t> lvars;
	std::map<std::string, size_t> lops;
	std::map<std::string, size_t> llits;
	std::string words = seperateWords(line);
	auto keys = getKeys(words);
	auto vars = getVars(words);
	auto ops = getOps(line);	// getOps needs non-seperated line
	auto lits = getLits(words);
	size_t pos = 0;
	//for (int i = 0; i < keys.size(); i++)
	for (auto x : keys)
	{
		//pos = line.find(keys[i], pos);
		pos = line.find(x, pos);
		//lkeys.insert(std::pair<size_t, std::string>(pos++, keys[i]));
		lkeys.insert(std::make_pair(x, pos++));
	}
	pos = 0;
	//for (int i = 0; i < vars.size(); i++)
	for (auto x : vars)
	{
		//pos = line.find(vars[i], pos);
		pos = line.find(x, pos);
		//lvars.insert(std::pair<size_t, std::string>(pos++, vars[i]));
		lvars.insert(std::make_pair(x, pos++));
	}
	pos = 0;
	//for (int i = 0; i < ops.size(); i++)
	for (auto x : ops)
	{
		//pos = line.find(ops[i], pos);
		pos = line.find(x, pos);
		//lops.insert(std::pair<size_t, std::string>(pos++, ops[i]));
		lops.insert(std::make_pair(x, pos++));
	}
	pos = 0;
	//for (int i = 0; i < lits.size(); i++)
	for (auto x : lits)
	{
		//pos = line.find(lits[i], pos);
		pos = line.find(x, pos);
		//llits.insert(std::pair<size_t, std::string>(pos++, lits[i]));
		llits.insert(std::make_pair(x, pos++));
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

std::vector<std::string> Tokenizer::getKeys(std::string line)
{
	auto words = getWords(line);
	std::vector<std::string> keys;
	for (auto x : words)
	{
		if (keywords.count(x) != 0)
		{
			keys.push_back(x);
		}
	}
	return keys;
}

std::vector<std::string> Tokenizer::getVars(std::string line)
{
	auto words = getWords(line);
	std::vector<std::string> vars;
	for (auto x : words)
	{
		if (keywords.count(x) == 0)
		{
			if (!isdigit(x[0]))
			{
				vars.push_back(x);
			}
		}
	}
	return vars;
}

std::vector<std::string> Tokenizer::getOps(std::string line)
{
	std::vector<std::string> ops;
	size_t x = 0;
	if (x = line.find("+") != std::string::npos)
	{
		ops.push_back("+");
		while (x != std::string::npos)
		{
			x = line.find("+", ++x);
			if (x != std::string::npos)
			{
				ops.push_back("+");
			}
		}
	}
	if (x = line.find("-") != std::string::npos)
	{
		ops.push_back("-");
		while (x != std::string::npos)
		{
			x = line.find("-", ++x);
			if (x != std::string::npos)
			{
				ops.push_back("-");
			}
		}
	}
	if (x = line.find("*") != std::string::npos)
	{
		ops.push_back("*");
		while (x != std::string::npos)
		{
			x = line.find("*", ++x);
			if (x != std::string::npos)
			{
				ops.push_back("*");
			}
		}
	}
	if (x = line.find("/") != std::string::npos)
	{
		ops.push_back("/");
		while (x != std::string::npos)
		{
			x = line.find("/", ++x);
			if (x != std::string::npos)
			{
				ops.push_back("/");
			}
		}
	}
	if (x = line.find("=") != std::string::npos)
	{
		ops.push_back("=");
		while (x != std::string::npos)
		{
			x = line.find("=", ++x);
			if (x != std::string::npos)
			{
				ops.push_back("=");
			}
		}
	}
	return ops;
}

std::vector<std::string> Tokenizer::getLits(std::string line)
{
	auto words = getWords(line);
	std::vector<std::string> lits;
	bool isnum;
	for (auto x : words)
	{
		isnum = true;
		for (unsigned int i = 0; i < x.size(); i++)
		{
			if (!isdigit(x[i]))
			{
				isnum = false;
			}
		}
		if (isnum)
		{
			lits.push_back(x);
		}
	}
	return lits;
}

std::vector<std::string> Tokenizer::getWords(std::string line)
{
	std::vector<std::string> result;
	std::string word;
	for (std::string::iterator it = line.begin(); it != line.end(); it++)
	{
		if (*it != ' ')
		{
			word += *it;
		}
		else
		{
			if (word.length() > 0)
			{
				/*
				if (word[0] >= '0' && word[0] <= '9')
				{
					word.clear();
				}
				else
				{
					result.push_back(word);
					word.clear();
				}
				*/
				result.push_back(word);
				word.clear();
			}
		}
	}
	return result;
}

std::vector<LineType> Tokenizer::findType(Line* line)
{
	std::vector<LineType> types;
	if (!line->lkeys.empty())
	{
		for (auto x : line->lkeys)
		{
			if (x.first == "int")
			{
				types.push_back(decl);
			}
			if (x.first == "if" || x.first == "else")
			{
				types.push_back(cond);
			}
		}
	}
	if (!line->lops.empty())
	{
		for (auto x : line->lops)
		{
			if (x.first == "+" || x.first == "-" || x.first == "*" || x.first == "/")
			{
				types.push_back(arith);
			}
			if (x.first == "=")
			{
				types.push_back(assign);
			}
		}
	}
	std::sort(types.begin(), types.end());
	return types;
}

void Tokenizer::buildKeywords()
{
	keywords.insert("int");
	keywords.insert("if");
	keywords.insert("else");
}

Line* Tokenizer::getLineData(int index)
{
	return lines[index];
}

int Tokenizer::getSize()
{
	return size;
}