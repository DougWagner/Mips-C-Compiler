#include "MipsCompiler.h" 
int main()
{
 	std::string infile = "FileStructure.cpp";
 	MipsCompiler run = MipsCompiler(infile);
	run.printFile();
 	system("pause");
 	return 0;
}