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
	int arithType = 0;
	int checkName1 = 0;
	int checkName2 = 0;
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
							   
class Subtraction : public virtual Arithmetic
{
public:
	Subtraction() {}
	Subtraction(std::string, std::string, std::string);
	std::string arithmeticOp();
};

class Multiplication : public virtual Arithmetic
{
public:
	Multiplication() {}
	Multiplication(std::string, std::string, std::string);
	std::string arithmeticOp();
};

class Division : public virtual Arithmetic
{
public:
	Division() {}
	Division(std::string, std::string, std::string);
	std::string arithmeticOp();
};
