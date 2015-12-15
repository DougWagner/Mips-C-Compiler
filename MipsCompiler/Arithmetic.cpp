#include "Arithmetic.h"

Arithmetic::Arithmetic(std::string n1,
	std::string n2, std::string n3)
{
	name1 = n1;
	name2 = n2;
	name3 = n3;
	for (int i = 0; i < name1.length(); i++)
	{
		if (!isdigit(name1[i]))
		{
			checkName1 = 0;
			break;
		}
		checkName1 = 1;
	}
	for (int i = 0; i < name2.length(); i++)
	{
		if (!isdigit(name2[i]))
		{
			checkName2 = 0;
			break;
		}
		checkName2 = 1;
	}
	arithType = checkName1 + checkName2;
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
	if (arithType == 0)
	{
		ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
			name2 << "($zero)\n\t\tadd $t2, $t0, $t1" << std::endl
			<< "\t\tsw $t2, " << name3 << std::endl;
	}
	if (arithType == 1)
	{
		ss << "\t\tlw $t0, " << name1 << "($zero)" << 
			  "\n\t\taddi $t2, $t0, " << name2 << std::endl << 
			  "\t\tsw $t2, " << name3 << std::endl;
	}
	if (arithType == 2)
	{
		ss << "\t\tli $t0, " << name1 << std::endl <<
			"\t\tli $t1, " << name2 << std::endl <<
			"\t\tadd $t2, $t0, $t1" << std::endl <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
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
	/*
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tsub $t2, $t0, $t1" << std::endl
		<< "\t\tsw $t2, " << name3 << std::endl;
	*/
	if (arithType == 0)
	{
		ss <<  "\t\tlw $t0, " << name1 << 
			   "($zero)\n\t\tlw $t1, " << name2 << 
			   "($zero)\n\t\tsub $t2, $t0, $t1" << std::endl << 
			   "\t\tsw $t2, " << name3 << std::endl;
	}
	if (arithType == 1)
	{
		ss << "\t\tlw $t0, " << name1 << "($zero)" <<
			"\n\t\tsubi $t2, $t0, " << name2 << std::endl <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	if (arithType == 2)
	{
		ss << "\t\tli $t0, " << name1 << std::endl <<
			"\t\tli $t1, " << name2 << std::endl <<
			"\t\tsub $t2, $t0, $t1" << std::endl <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
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
	if (arithType == 0)
	{
		ss << "\t\tlw $t0, " << name1 << std::endl <<
			"($zero)\n\t\tlw $t1, " << name2 <<
			"($zero)\n\t\tmult $t0, $t1" << std::endl <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	else if (arithType == 1)
	{
		ss << "\t\tlw $t0, " << name1 << "($zero)" << std::endl <<
			"\t\tli $ti, " << name2 << std::endl <<
			"\t\tmult $t0, $t1\n" <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	else if (arithType == 2)
	{
		ss << "\t\tli $t0, " << name1 << std::endl <<
			"\t\tli $ti, " << name2 << std::endl <<
			"\t\tmult $t0, $t1\n" <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	
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
	/*
	ss << "\t\tlw $t0, " << name1 << "($zero)\n\t\tlw $t1, " <<
		name2 << "($zero)\n\t\tdiv $t0, $t1" << std::endl
		<<	"\t\tmflo $t2\n"
		<< "\t\tsw $t2, " << name3 << std::endl;
	*/
	if (arithType == 0)
	{
		ss << "\t\tlw $t0, " << name1 << std::endl <<
			"($zero)\n\t\tlw $t1, " << name2 <<
			"($zero)\n\t\tdiv $t0, $t1" << std::endl <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	else if (arithType == 1)
	{
		ss << "\t\tlw $t0, " << name1 << "($zero)" << std::endl <<
			"\t\tli $ti, " << name2 << std::endl <<
			"\t\tdiv $t0, $t1\n" <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}
	else if (arithType == 2)
	{
		ss << "\t\tli $t0, " << name1 << std::endl <<
			"\t\tli $ti, " << name2 << std::endl <<
			"\t\tdiv $t0, $t1\n" <<
			"\t\tmflo $t2\n" <<
			"\t\tsw $t2, " << name3 << std::endl;
	}

	return ss.str();
}

