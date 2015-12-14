#include "Arithmetic.h"

Arithmetic::Arithmetic(std::string n1,
	std::string n2, std::string n3)
{
	name1 = n1;
	name2 = n2;
	name3 = n3;
}
Addition::Addition(std::string n1,
	std::string n2, std::string n3) :
	Arithmetic(n1, n2, n3)
{

}
std::string Addition::arithmeticOp()
{
	// This Assumes that the two variables being added are declared!
	std::stringstream ss;
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tadd $t2, $t0, $t1" << std::endl
		<<"\t\tsw $t2, " << name3 << std::endl;
	return ss.str();
}
Subtraction::Subtraction(std::string n1, 
	std::string n2, std::string n3) :
	Arithmetic(n1, n2, n3)
{

}
std::string Subtraction::arithmeticOp()
{
	// This Assumes that the two variables being added are declared!
	std::stringstream ss;
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tsub $t2, $t0, $t1" << std::endl
		<< "\t\tsw $t2, " << name3 << std::endl;
	return ss.str();
}
Multiplication::Multiplication(std::string n1,
	std::string n2, std::string n3) :
	Arithmetic(n1, n2, n3)
{

}
std::string Multiplication::arithmeticOp()
{
	// This Assumes that the two variables being added are declared!
	std::stringstream ss;
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tmult $t0, $t1" << std::endl
		<< "\t\tmflo $t2\n"
		<< "\t\tsw $t2, " << name3 << std::endl;
	return ss.str();
}
Division::Division(std::string n1,
	std::string n2, std::string n3) :
	Arithmetic(n1, n2, n3)
{

}
std::string Division::arithmeticOp()
{
	// This Assumes that the two variables being added are declared!
	std::stringstream ss;
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tdiv $t0, $t1" << std::endl
		<<	"\t\tmflo $t2\n"
		<< "\t\tsw $t2, " << name3 << std::endl;
	return ss.str();
}

