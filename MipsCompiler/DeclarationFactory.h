#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_set>
#include "VariableDeclarations.h"



class DeclarationFactory 
{
protected:
	IntDeclaration* intDec;
public:
	DeclarationFactory() {}
	DeclarationFactory(Line*);
	IntDeclaration* getIntDec() { return intDec; }
};