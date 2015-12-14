#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

#include "Tokenizer.h"
#include "ArithmeticFactory.h"
#include "DeclarationFactory.h"
class LineHandler
{
private:
	ArithmeticFactory arith;
	DeclarationFactory decl;
protected:

public:
	LineHandler() {}
	LineHandler(Tokenizer);
};