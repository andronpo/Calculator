#pragma once
#include <string>

class Calculatable		//общий интерфейс для классов Number и Expression. Нужен для использования паттерна Компоновщик
{
public:
	virtual double calculate() = 0;
};

