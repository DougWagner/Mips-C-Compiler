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
class Arithmetic
{

protected:
	std::string name1, name2, name3;
public:
	Arithmetic(std::string, std::string, std::string);
	virtual std::string arithmeticOp() = 0;
};

class Addition : private virtual Arithmetic
{
public:
	Addition(std::string, std::string, std::string);
	std::string arithemticOp() override;
};
							   
class Subtraction : private Arithmetic
{
public:
	Subtraction(std::string, std::string, std::string);
	std::string arithemticOp();
};

class Multiplication : private Arithmetic
{
public:
	Multiplication(std::string, std::string, std::string);
	std::string arithemticOp();
};

class Division : private Arithmetic
{
public:
	Division(std::string, std::string, std::string);
	std::string arithemticOp();
};