#include "MipsCompiler.h"

// Ensure in main() that the file is valid before passing to MipsCompiler constructor
MipsCompiler::MipsCompiler(std::ifstream& file)
{
	LineParser parser = LineParser(file);
	parser.readFile();
}
