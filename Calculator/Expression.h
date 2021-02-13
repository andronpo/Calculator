#pragma once
#include "Calculatable.h"

class Expression : public Calculatable			//Expression служит контейнером дл€ чисел или же других выражений
{
public:
	Expression();
	~Expression();
	Expression(Calculatable* lvalue, Calculatable* rvalue, char operation);

	virtual double calculate() override;		//в реализации метода, вычисление результата делигируетс€ дочерним компонентам
	virtual void clear() override;

private:
	char operation;
	Calculatable* lvalue;
	Calculatable* rvalue;

};

 