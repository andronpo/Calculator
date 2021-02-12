#include "Calculator.h"

Calculator::Calculator()
{
}

Calculator::~Calculator()
{
}

double Calculator::calculate(Calculatable* expression)
{
    return expression->calculate();
}
