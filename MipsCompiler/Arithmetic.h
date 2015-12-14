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
	int iVar1, iVar2;
	std::string name1, name2, name3;
public:
	Arithmetic(std::string, int, std::string, int, std::string);
	virtual int getFirstVar() = 0;
	virtual int getSecVar() = 0;
	virtual std::string arithmeticOp() = 0;
};

class Addition : private Arithmetic
{
public:
	Addition(std::string, int, std::string, int, std::string);
	virtual int getFirstVar() { return iVar1; }
	virtual int getSecVar() { return iVar2; }
	virtual std::string arithemticOp();
};

class Subtraction : private Arithmetic
{
public:
	Subtraction(std::string, int, std::string, int, std::string);
	virtual int getFirstVar() { return iVar1; }
	virtual int getSecVar() { return iVar2; }
	virtual std::string arithemticOp();
};

class Multiplication : private Arithmetic
{
public:
	Multiplication(std::string, int, std::string, int, std::string);
	virtual int getFirstVar() { return iVar1; }
	virtual int getSecVar() { return iVar2; }
	virtual std::string arithemticOp();
};

class Division : private Arithmetic
{
public:
	Division(std::string, int, std::string, int, std::string);
	virtual int getFirstVar() { return iVar1; }
	virtual int getSecVar() { return iVar2; }
	virtual std::string arithemticOp();
};