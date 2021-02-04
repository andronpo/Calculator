#pragma once
#include "Calculatable.h"

class Expression : public Calculatable
{
	Expression();
	~Expression();
	Expression(std::string expression);


	Calculatable* lvalue;
	Calculatable* rvalue;
	
	virtual int calculate() override;

};

 