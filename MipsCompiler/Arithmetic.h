#pragma once
#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <unordered_set>
#include "Tokenizer.h"
#include <sstream>

class Arithmetic
{

protected:
	std::string name1, name2, name3;
public:
	Arithmetic() {}
	Arithmetic(std::string, std::string, std::string);
	virtual std::string arithmeticOp() = 0;
};

class Addition : public virtual  Arithmetic
{
public:
	Addition() {}
	Addition(std::string, std::string, std::string);
	std::string arithmeticOp();
};
							   
class Subtraction : private Arithmetic
{
public:
	Subtraction(std::string, std::string, std::string);
	std::string arithmeticOp();
};

class Multiplication : private Arithmetic
{
public:
	Multiplication(std::string, std::string, std::string);
	std::string arithmeticOp();
};

class Division : private Arithmetic
{
public:
	Division(std::string, std::string, std::string);
	std::string arithmeticOp();
};
