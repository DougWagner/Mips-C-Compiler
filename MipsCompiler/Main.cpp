#include "MipsCompiler.h" 
int main()
{
 	std::string file1 = "test1.txt";
	std::string file2 = "test2.txt";
	std::string file3 = "test3.txt";
	std::string file4 = "test4.txt";
	std::string out1 = "output1.s";
	std::string out2 = "output2.s";
	std::string out3 = "output3.s";
	std::string out4 = "output4.s";
 	MipsCompiler run = MipsCompiler(file1, out1);
	run.printFile();
	run = MipsCompiler(file2, out2);
	run.printFile();
	run = MipsCompiler(file3, out3);
	run.printFile();
	run = MipsCompiler(file4, out4);
	run.printFile();
 	system("pause");
 	return 0;
}