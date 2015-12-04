#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <unordered_map>
#include <unordered_set>
#include "Arithmetic.h"
class ArithmeticFactory
{
private:
public:
	ArithmeticFactory();
	std::string convertAddToMips();
	std::string convertSubToMips();
	std::string convertMulToMips();
	std::string convertDivToMips();

};
