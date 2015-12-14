#include "Output.h"

Output::Output()
{
	output.push_back("\t\t.data\n");
	dataloc = output.begin();
	codeloc = output.begin();
	//dataloc = 0;
	output.push_back("\t\t.text\n");
	dataloc++;
	codeloc++;
	//textloc = 1;
	output.push_back("\t\t.globl main\n");
	codeloc++;
	//globlloc = 2;
	output.push_back("main:\n");
	codeloc++;
	//mainloc = 3;
	output.push_back("\t\tjr $ra\n");
	codeloc++;
	//exitloc = 4;
}

void Output::insertData(std::string data)
{
	output.insert(dataloc, data);
}

void Output::insertCode(std::string data)
{
	output.insert(codeloc, data);
}

void Output::print()
{
	for (auto x : output)
	{
		std::cout << x;
	}
}

void Output::printToFile(std::string outputFile)
{
	std::ofstream outfile(outputFile);
	for (auto x : output)
	{
		outfile << x;
	}
	outfile.close();
}