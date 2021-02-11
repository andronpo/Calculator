#pragma once
#include "Calculatable.h"

class Expression : public Calculatable
{
	Expression();
	~Expression();
	Expression(Calculatable* lvalue, Calculatable* rvalue, char operation);

	char operation;
	Calculatable* lvalue;
	Calculatable* rvalue;
	
	virtual double calculate() override;

};

 