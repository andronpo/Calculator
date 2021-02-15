#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Calculatable		//����� ��������� ��� ������� Number � Expression. ����� ��� ������������� �������� �����������
{
public:
	virtual double calculate() = 0;
	virtual void clear() = 0;
};

