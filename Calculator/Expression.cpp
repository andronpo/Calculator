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
	switch (this->operation)
	{
		case '*':
		{
			return lvalue->calculate() * rvalue->calculate();
		}
		case '+':
		{
			return lvalue->calculate() + rvalue->calculate();
		}
		case '-':
		{
			return lvalue->calculate() - rvalue->calculate();
		}
		case '/':
		{
			return lvalue->calculate() / rvalue->calculate();
		}
	}
}

void Expression::clear()
{
	this->lvalue->clear();
	this->rvalue->clear();
	delete this->lvalue;
	delete this->rvalue;
}
