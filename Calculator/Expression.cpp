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
	// свитч на определение действия + - * /
	return lvalue->calculate() +  rvalue->calculate();
}
