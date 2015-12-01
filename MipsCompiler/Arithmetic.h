#pragma once
#include "MipsCompiler.h"
class Arithmetic
{

private:
	int iVar1, iVar2;
public:
	Arithmetic();
	virtual int getFirstVar() = 0;
	virtual int getSecVar() = 0;
	virtual void arithmeticOp() = 0;
};

class Addition : private Arithmetic
{
public:
	Addition();
};

class Subtraction : private Arithmetic
{
public:
	Subtraction();
};

class Multiplication : private Arithmetic
{
public:
	Multiplication();
};

class Division : private Arithmetic
{
	Division();
};