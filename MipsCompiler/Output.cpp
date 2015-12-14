#include "Output.h"

Output::Output()
{
	output.push_back("\t\t.data\n");
	dataloc = 0;
	output.push_back("\t\t.text\n");
	textloc = 1;
	output.push_back("\t\t.globl main\n");
	globlloc = 2;
	output.push_back("main:\n");
	mainloc = 3;
	output.push_back("\t\t\tjr $ra\n");
	exitloc = 4;
}