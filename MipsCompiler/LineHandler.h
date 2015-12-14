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

class LineHandler
{
private:
	ArithmeticFactory arithFact;
	DeclarationFactory declFact;
protected:
	void sendToFactory(Line*);
public:
	LineHandler() {}
	LineHandler(Tokenizer);
};