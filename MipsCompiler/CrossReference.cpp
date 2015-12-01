#include "CrossReference.h"

/*	Cross Reference Constructor
*	String parameter should be a file path for a .cpp file
*
*	The constructor will open the file provided, and send it to the readFile function,
*	where all of the work is done and stored in the object. Returned object contains the completed
*	cross reference, and will allow for printing to command line, or to .txt file.
*/
CrossReference::CrossReference(std::string filename)
{
	buildKeywords();
	std::ifstream infile(filename, std::ifstream::in);
	if (!infile)
	{
		std::cout << "There was a problem opening the file." << std::endl;
		return;
	}
	readFile(infile);
	sortMap();
	infile.close();
}

/*	Cross Reference Read File method
*	Parameter is a valid file, checked by constructor.
*
*	This function loops through the file line by line, and sends each line through the functions
*	checkQuotes, checkComments, checkCommentBlocks, seperateWords, and parseLine. The order of these
*	functions is important, to make sure that each function doesn't erase necessary information from
*	each line.
*
*	Commented cout lines were for debug purposes.
*/
void CrossReference::readFile(std::ifstream& file)
{
	std::string line;
	bool commentBlock = false;
	std::pair<std::string, bool> blockCheck;
	unsigned int linenumber = 1;
	while (!file.eof())
	{
		std::getline(file, line);
		//std::cout << linenumber << "\t" << line << std::endl;
		if (!commentBlock)
		{
			line = checkQuotes(line);
			//std::cout << "checkQuotes: " << line << std::endl;
		}
		line = checkComments(line);
		//std::cout << "checkComments: " << line << std::endl;
		blockCheck = checkCommentBlocks(line, commentBlock);
		line = std::get<0>(blockCheck);
		commentBlock = std::get<1>(blockCheck);
		//std::cout << "checkCommentBlocks: " << line << std::endl;
		line = seperateWords(line);
		//std::cout << "seperateWords: " << line << std::endl;
		parseLine(line, linenumber++);
	}
}

/*	Cross Reference Check Quotes Method
*	Parameter is a string containing the current line from readFile
*
*	This function recursively removes any text contained by single and double quotations in the line while
*	accommodating for escaped quotation characters. The function will check the line for quotations, remove
*	the text from the line, and return a recursive call to checkQuotes, until it finds no quotes in the line
*	and returns the final result.
*/
std::string CrossReference::checkQuotes(std::string line)
{
	size_t valDoubleQuote = line.find("\"");
	size_t valSingleQuote = line.find("'");
	bool doubleQuote = false;
	bool singleQuote = false;

	// Determine if quotes are double or single
	if (valDoubleQuote != std::string::npos && valSingleQuote != std::string::npos)
	{
		// Determine if double quotes or single quotes is first in line
		if (valDoubleQuote < valSingleQuote)
		{
			doubleQuote = true;
		}
		else
		{
			singleQuote = true;
		}
	}
	else if (valDoubleQuote != std::string::npos)
	{
		doubleQuote = true;
	}
	else if (valSingleQuote != std::string::npos)
	{
		singleQuote = true;
	}

	// remove all text within double quotes
	if (doubleQuote)
	{
		size_t newValDoubleQuote = line.find("\"", valDoubleQuote + 1);
		while (line[newValDoubleQuote - 1] == '\\' && line[newValDoubleQuote - 2] != '\\')
		{
			newValDoubleQuote = line.find("\"", newValDoubleQuote + 1);
		}
		line.erase(valDoubleQuote, newValDoubleQuote - valDoubleQuote + 1);
	}

	// remove all text within single quotes
	else if (singleQuote)
	{
		size_t newValSingleQuote = line.find("'", valSingleQuote + 1);
		while (line[newValSingleQuote - 1] == '\\' && line[newValSingleQuote - 2] != '\\')
		{
			newValSingleQuote = line.find("'", newValSingleQuote + 1);
		}
		line.erase(valSingleQuote, newValSingleQuote - valSingleQuote + 1);
	}

	// return line if no quotes found
	else {
		return line;
	}

	// if quotes found, check the line recursively for any more quotes.
	return checkQuotes(line);
}

/*	Cross Reference Check Comments Method
*	Parameter is a string containing the current line from readFile
*
*	This function checks the string for any instance of two slashes "//" and removes all text that comes
*	after, including the two slashes.
*/
std::string CrossReference::checkComments(std::string line)
{
	size_t val = line.find("//");
	if (val != std::string::npos)
	{
		line.erase(val, std::string::npos);
	}
	return line;
}

/*	Cross Reference Check Comment Blocks Method
*	Parameters are a string containing the current line from readFile, and a boolean containing
*	the condition of whether or not line is within an already opened comment block.
*
*	This function checks the string for an instance of the the comment block start and end identifiers.
*	The function will accomidate comment blocks that span many lines, comment blocks that open and close
*	on the same line, and comment blocks that close, and then open on the same line after a statement.
*	The function will remove any text contained within comment blocks, and if the entire line is within
*	a comment block, the entire line will be erased. The function returns a std::pair containing the modified
*	line, and a boolean containing the condition of whether or not a comment block was opened or not.
*/
std::pair<std::string, bool> CrossReference::checkCommentBlocks(std::string line, bool condition)
{
	size_t startVal = line.find("/*");
	size_t endVal = line.find("*/");

	// If line not within opened comment block
	if (!condition)
	{
		// Checks if comment block opens and closes on same line
		if (startVal != std::string::npos && endVal != std::string::npos)
		{
			line.erase(startVal, endVal - startVal + 2);
			return std::make_pair(line, false);
		}
		// If comment block opens but does not close on line, condition will be set to true
		else if (startVal != std::string::npos)
		{
			line.erase(startVal, std::string::npos);
			return std::make_pair(line, true);
		}
		// If no comment block found, return unchanged line
		else
		{
			return std::make_pair(line, false);
		}
	}

	// If line within opened comment block
	else
	{
		// If comment block closes, but new comment block is opened on same line
		if (endVal != std::string::npos && startVal != std::string::npos)
		{
			if (endVal < startVal)
			{
				line.erase(0, endVal);
				line.erase(startVal, std::string::npos);
				return std::make_pair(line, true);
			}
			// else clause for if start block characters found within already existing comment block
			else
			{
				line.erase(0, endVal);
				return std::make_pair(line, false);
			}
		}
		// If opened comment block is closed
		else if (endVal != std::string::npos)
		{
			line.erase(0, endVal);
			return std::make_pair(line, false);
		}
		// If comment block is open and no closing identifier found
		else
		{
			line.erase(0, std::string::npos);
			return std::make_pair(line, true);
		}
	}
}

/*	Cross Reference Seperate Words Method
*	Parameter is a string containing the current line from readFile
*
*	This method iterates through the line and replaces all invalid variable characters with whitespace,
*	and returns the new modified line.
*/
std::string CrossReference::seperateWords(std::string line)
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

/*	Cross Reference Parse Line Method
*	Parameters are a string containing the current line, and an integer for file line number
*
*	This method sends the line split by seperateWords to the getWords function, and then checks them
*	against the keywords and varNames lists. If the word is not in keywords and not in varNames, it
*	will create a new entry in varNames with place a vector containing the line number. If the word is
*	not in keywords but is found in varNames, then it will add the line number to the keyword's associated
*	vector if the line number is not already in the vector.
*/
void CrossReference::parseLine(std::string line, int lnum)
{
	std::vector<std::string> vLineWords = getWords(line);
	for (int i = 0; i < vLineWords.size(); i++)
	{
		if (keywords.count(vLineWords[i]) == 0 && varNames.count(vLineWords[i]) == 0)
		{
			std::vector<int>vLineNums;
			vLineNums.push_back(lnum);
			varNames.insert({ vLineWords[i], vLineNums });
		}
		else if (varNames.count(vLineWords[i]) > 0)
		{
			std::unordered_map<std::string, std::vector<int>>::iterator mapIt = varNames.find(vLineWords[i]);
			if (std::find(mapIt->second.begin(), mapIt->second.end(), lnum) == mapIt->second.end())
			{
				mapIt->second.push_back(lnum);
			}
		}
	}
}

/*	Cross Reference Get Words Method
*	Parameter is a string containing the current line.
*
*	This function will take the line split by seperateWords and iterate through it to get each individual
*	word from the line and places each word into a vector which gets returned at the end.
*/
std::vector<std::string> CrossReference::getWords(std::string line)
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
				if (word[0] >= '0' && word[0] <= '9')
				{
					word.clear();
				}
				else
				{
					result.push_back(word);
					word.clear();
				}
			}
		}
	}
	return result;
}

void CrossReference::sortMap()
{
	for (auto x : varNames)
	{
		sortedNames.insert(x);
	}
}

/*	Cross Reference Build Keywords Method
*
*	This method places all of the common C++ keywords into the keywords unordered_set.
*/
void CrossReference::buildKeywords()
{
	keywords.insert("alignas");
	keywords.insert("alignof");
	keywords.insert("and");
	keywords.insert("and_eq");
	keywords.insert("asm");
	keywords.insert("auto");
	keywords.insert("bitand");
	keywords.insert("bitor");
	keywords.insert("bool");
	keywords.insert("break");
	keywords.insert("case");
	keywords.insert("catch");
	keywords.insert("char");
	keywords.insert("char16_t");
	keywords.insert("char32_t");
	keywords.insert("class");
	keywords.insert("compl");
	keywords.insert("concept");
	keywords.insert("const");
	keywords.insert("constexpr");
	keywords.insert("const_cast");
	keywords.insert("continue");
	keywords.insert("decltype");
	keywords.insert("default");
	keywords.insert("delete");
	keywords.insert("do");
	keywords.insert("double");
	keywords.insert("dynamic_cast");
	keywords.insert("else");
	keywords.insert("enum");
	keywords.insert("explicit");
	keywords.insert("export");
	keywords.insert("extern");
	keywords.insert("false");
	keywords.insert("float");
	keywords.insert("for");
	keywords.insert("friend");
	keywords.insert("goto");
	keywords.insert("if");
	keywords.insert("inline");
	keywords.insert("int");
	keywords.insert("long");
	keywords.insert("mutable");
	keywords.insert("namespace");
	keywords.insert("new");
	keywords.insert("noexcept");
	keywords.insert("not");
	keywords.insert("not_eq");
	keywords.insert("nullptr");
	keywords.insert("operator");
	keywords.insert("or");
	keywords.insert("or_eq");
	keywords.insert("private");
	keywords.insert("protected");
	keywords.insert("public");
	keywords.insert("register");
	keywords.insert("reinterpret_cast");
	keywords.insert("requires");
	keywords.insert("return");
	keywords.insert("short");
	keywords.insert("signed");
	keywords.insert("sizeof");
	keywords.insert("static");
	keywords.insert("static_assert");
	keywords.insert("static_cast");
	keywords.insert("struct");
	keywords.insert("switch");
	keywords.insert("template");
	keywords.insert("this");
	keywords.insert("thread_local");
	keywords.insert("throw");
	keywords.insert("true");
	keywords.insert("try");
	keywords.insert("typedef");
	keywords.insert("typeid");
	keywords.insert("typename");
	keywords.insert("union");
	keywords.insert("unsigned");
	keywords.insert("using");
	keywords.insert("virtual");
	keywords.insert("void");
	keywords.insert("volatile");
	keywords.insert("wchar_t");
	keywords.insert("while");
	keywords.insert("xor");
	keywords.insert("xor_eq");
	keywords.insert("elif");
	keywords.insert("endif");
	keywords.insert("defined");
	keywords.insert("ifdef");
	keywords.insert("ifndef");
	keywords.insert("define");
	keywords.insert("undef");
	keywords.insert("include");
	keywords.insert("pragma");
	keywords.insert("std");
	keywords.insert("iostream");
	keywords.insert("NULL");
	keywords.insert("cout");
	keywords.insert("cin");
	keywords.insert("cerr");
	keywords.insert("endl");
	keywords.insert("fstream");
	keywords.insert("ifstream");
	keywords.insert("ofstream");
	keywords.insert("string");
	keywords.insert("cstdlib");
	keywords.insert("ctime");
	keywords.insert("rand");
	keywords.insert("srand");
	keywords.insert("time");
	keywords.insert("system");
	keywords.insert("unordered_set");
	keywords.insert("unordered_map");
	keywords.insert("iterator");
}

/*	Cross Reference Print Results On Command Line Method
*
*	This function will print the contents of the varNames unordered_map
*/
/**/
void CrossReference::printResultsCmdLine()
{
	for (auto x : sortedNames)
	{
		std::cout << x.first << std::endl;
		for (int i = 0; i < x.second.size(); i++)
			std::cout << x.second[i] << " ";
		std::cout << std::endl << std::endl;
	}
}

/*	Cross Reference Print Results to File Method
*	Parameter is a string containing filename
*
*	This function will print the contents of the varNames unordered_map to a specified file. If the file already exists, it won't write.
*/
void CrossReference::printResultsToFile(std::string filename)
{
	if (fileExists(filename))
	{
		std::cout << "File already exists." << std::endl;
	}
	else
	{
		std::ofstream outfile(filename);
		for (auto x : sortedNames)
		{
			outfile << x.first << std::endl;
			for (int i = 0; i < x.second.size(); i++)
				outfile << x.second[i] << " ";
			outfile << std::endl << std::endl;
		}
	}
}

/*	Cross Reference File Exists Method
*	Parameter is a string containing filename
*
*	This function will check if a file already exists with the supplied filename. Only used in printResultsToFile
*/
bool CrossReference::fileExists(std::string filename)
{
	std::ifstream infile(filename);
	return infile.good();
}