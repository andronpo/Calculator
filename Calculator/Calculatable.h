#pragma once
#include <string>
#include <stdexcept>
#include <iostream>

class Calculatable		//общий интерфейс для классов Number и Expression. Нужен для использования паттерна Компоновщик
{
public:
	virtual double calculate() = 0;
	virtual void clear() = 0;
};

