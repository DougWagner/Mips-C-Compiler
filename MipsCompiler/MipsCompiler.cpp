#include "MipsCompiler.h"
/* old stuff
// Ensure in main() that the file is valid before passing to MipsCompiler constructor
MipsCompiler::MipsCompiler(std::ifstream& file)
{
	LineParser parser = LineParser(file);
	parser.readFile();
}
*/

MipsCompiler::MipsCompiler(std::string filename)
{
	initializeFile(filename);
	analyzeStructure();
}

void MipsCompiler::initializeFile(std::string filename)
{
	std::ifstream infile(filename, std::ifstream::in);
	if (!infile)
	{
		std::cout << "There was a problem opening the file" << std::endl;
		return;
	}
	std::string line;
	while (!infile.eof())
	{
		std::getline(infile, line);
		file.push_back(line);
	}
	infile.close();
}

void MipsCompiler::analyzeStructure()
{
	asdf = FileStructure(file);
}

void MipsCompiler::printFile()
{
	for (unsigned int i = 0; i < file.size(); i++)
	{
		std::cout << file[i] << std::endl;
	}
}