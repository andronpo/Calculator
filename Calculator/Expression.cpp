#include "Expression.h"

Expression::Expression()
{
}


Expression::~Expression()
{
}

Expression::Expression(std::string expression)
{
}

int Expression::calculate()
{
	// ����� �� ����������� �������� + - * /
	return lvalue->calculate() +  rvalue->calculate();
}
