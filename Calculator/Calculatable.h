#pragma once
#include <string>

class Calculatable		//����� ��������� ��� ������� Number � Expression. ����� ��� ������������� �������� �����������
{
public:
	virtual double calculate() = 0;
	virtual void clear() = 0;
};

