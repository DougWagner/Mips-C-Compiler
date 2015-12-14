#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_set>
#include "VariableAssign.h"

class AssignmentFactory
{
protected:
	IntAssign* intAssign;
public:
	AssignmentFactory() {}
	AssignmentFactory(Line*);
	IntAssign* getIntAssign() { return intAssign; }
};