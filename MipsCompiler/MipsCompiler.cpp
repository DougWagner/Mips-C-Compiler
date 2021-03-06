#include "MipsCompiler.h"

MipsCompiler::MipsCompiler(std::string filename, std::string outputFile)
{
	outfile = outputFile;
	initializeFile(filename);
	analyzeStructure();
	tokenize();
	handleLines();
	//printOutput();
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
	structure = FileStructure(file);
}

void MipsCompiler::tokenize()
{
	tokens = Tokenizer(file, structure);
}

void MipsCompiler::printFile()
{
	std::cout << "C CODE:" << std::endl << std::endl;
	for (unsigned int i = 0; i < file.size(); i++)
	{
		std::cout << file[i] << std::endl;
	}
	std::cout << std::endl;
	printOutput();
}

void MipsCompiler::handleLines()
{
	handler = LineHandler(tokens);
	out = handler.getOutput();
}

void MipsCompiler::printOutput()
{
	std::cout << "GENERATED MIPS CODE:" << std::endl << std::endl;
	out.print();
	out.printToFile(outfile);
	std::cout << std::endl;
}