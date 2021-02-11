#pragma once
#include "Calculatable.h"

class Calculator
{
public:
	Calculator();
	~Calculator();

	double calculate(Calculatable* expression);
};

