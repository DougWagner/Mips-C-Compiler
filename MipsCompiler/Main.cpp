#include "MipsCompiler.h" 
int main()
{
 	std::string infile = "test1.txt";
 	MipsCompiler run = MipsCompiler(infile);
	run.printFile();
 	system("pause");
 	return 0;
}