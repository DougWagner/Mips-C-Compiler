#include "Arithmetic.h"
Arithmetic::Arithmetic(std::string n1, int v1,
	std::string n2, int v2, std::string n3)
{
	name1 = n1;
	name2 = n2;
	name3 = n3;
	iVar1 = v1;
	iVar2 = v2;
}
Addition::Addition(std::string n1, int v1,
	std::string n2, int v2, std::string n3) :
	Arithmetic(n1, v1, n2, v2, n3)
{

}
std::string Addition::arithemticOp()
{
	// This Assumes that the two variables being added are declared!
	std::string s1 = ("lw $t0, %s($zero)\n", name1);
	std::string s2 = ("lw $t0, %s($zero)\n", name2);
	std::string s3 = "add $t2, $t0, $t1\n";
	std::string s4 = ("sw $t2, %s\n", name3);
	std::string converted = s1 + s2 + s3 + s4;
	return converted;
}
Subtraction::Subtraction(std::string n1, int v1,
	std::string n2, int v2, std::string n3) :
	Arithmetic(n1, v1, n2, v2, n3)
{

}
std::string Subtraction::arithemticOp()
{
	// This Assumes that the two variables being added are declared!
	std::string s1 = ("lw $t0, %s($zero)\n", name1);
	std::string s2 = ("lw $t0, %s($zero)\n", name2);
	std::string s3 = "sub $t2, $t0, $t1\n";
	std::string s4 = ("sw $t2, %s\n", name3);
	std::string converted = s1 + s2 + s3 + s4;
	return converted;
}
Multiplication::Multiplication(std::string n1, int v1,
	std::string n2, int v2, std::string n3) :
	Arithmetic(n1, v1, n2, v2, n3)
{

}
std::string Multiplication::arithemticOp()
{
	// This Assumes that the two variables being added are declared!
	std::string s1 = ("lw $t0, %s($zero)\n", name1);
	std::string s2 = ("lw $t0, %s($zero)\n", name2);
	std::string s3 = "mult $t2, $t0, $t1\n";
	std::string s4 = ("sw $t2, %s\n", name3);
	std::string converted = s1 + s2 + s3 + s4;
	return converted;
}
Division::Division(std::string n1, int v1,
	std::string n2, int v2, std::string n3) :
	Arithmetic(n1, v1, n2, v2, n3)
{

}
std::string Division::arithemticOp()
{
	// This Assumes that the two variables being added are declared!
	std::string s1 = ("lw $t0, %s($zero)\n", name1);
	std::string s2 = ("lw $t0, %s($zero)\n", name2);
	std::string s3 = "div $t2, $t0, $t1\n";
	std::string s4 = ("sw $t2, %s\n", name3);
	std::string converted = s1 + s2 + s3 + s4;
	return converted;
}

