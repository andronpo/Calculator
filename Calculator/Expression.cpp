#include "Expression.h"

Expression::Expression()
{
}


Expression::~Expression()
{
}

Expression::Expression(Calculatable* lvalue, Calculatable* rvalue, char operation)
{
	this->lvalue = lvalue;
	this->rvalue = rvalue;
	this->operation = operation;
}

double Expression::calculate()
{
	// ����� �� ����������� �������� + - * /
	return lvalue->calculate() +  rvalue->calculate();
}
