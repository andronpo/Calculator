#pragma once
#include "Calculatable.h"

class Expression : public Calculatable			//Expression ������ ����������� ��� ����� ��� �� ������ ���������
{
public:
	Expression();
	~Expression();
	Expression(Calculatable* lvalue, Calculatable* rvalue, char operation);

	virtual double calculate() override;		//� ���������� ������, ���������� ���������� ������������ �������� �����������
	virtual void clear() override;

private:
	char operation;
	Calculatable* lvalue;
	Calculatable* rvalue;

};

 