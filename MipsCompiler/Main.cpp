#include "MipsCompiler.h" 
int main()
{
 	std::ifstream infile("Main.cpp");
 	MipsCompiler run = MipsCompiler(infile);
 	system("pause");
 	return 0;
}