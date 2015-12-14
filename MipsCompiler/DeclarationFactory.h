#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_set>
#include "VariableDeclarations.h"

#pragma once

class DeclarationFactory {
public:
	DeclarationFactory(Tokenizer*, FileStructure*);
};