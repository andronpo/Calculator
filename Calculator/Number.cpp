#include "Number.h"

Number::Number()
{
}

Number::~Number()
{
}

Number::Number(std::string* value)
{
	this->value = value;
}

double Number::calculate()
{
	double value;
	try {
		value = std::stod(*(this->value));
	}
	catch(const std::invalid_argument&){				//��������� ���������� � ������, ���� � ������ ���� ����������� �������
		std::cerr << *this->value << " not a number";
		exit(0);
	}
	return value;
}
