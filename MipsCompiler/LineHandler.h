#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>

#include "ArithmeticFactory.h"
#include "DeclarationFactory.h"
#include "AssignmentFactory.h"

class LineHandler
{
private:
	DeclarationFactory declFact;
	ArithmeticFactory arithFact;
	AssignmentFactory assignFact;
protected:
	void sendToFactory(Line*, LineType);
public:
	LineHandler() {}
	LineHandler(Tokenizer);
};