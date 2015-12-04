#include "MipsCompiler.h" 
int main()
{
 	std::string infile = "testfile.cpp";
 	MipsCompiler run = MipsCompiler(infile);
	run.printFile();
 	system("pause");
 	return 0;
}