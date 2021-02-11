#include "Number.h"

Number::Number()
{
}

Number::~Number()
{
}

Number::Number(std::string value)
{
	this->value = value;
}

double Number::calculate()
{
	return std::stod(this->value);
}
