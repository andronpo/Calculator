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
			return this->lvalue->calculate() * this->rvalue->calculate();
		}
		case '+':
		{
			return this->lvalue->calculate() + this->rvalue->calculate();
		}
		case '-':
		{
			return this->lvalue->calculate() - this->rvalue->calculate();
		}
		case '/':
		{
			double rightValue = this->rvalue->calculate();
			try
			{
				if (rightValue == 0) {
					throw 1;
				}
				return this->lvalue->calculate() / rightValue;
			}
			catch (int err) {								//обработка исключения в случае, если знаменатель равен 0
				std::cerr << "divisoin by zero";
				exit(err);
			}
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
