#include "MipsCompiler.h" 
// this is a branch test
int main()
{
 	std::string infile = "test1.txt";
	std::string outputfile = "output1.s";
 	MipsCompiler run = MipsCompiler(infile, outputfile);
	run.printFile();
 	system("pause");
 	return 0;
}