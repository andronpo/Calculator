#pragma once
#include "Calculatable.h"
#include <stdexcept>
#include <iostream>

class Number :                              //простейший компонент выражения
    public Calculatable
{
public:
    Number();
    ~Number();
    Number(std::string* value);

    virtual double calculate() override;    //в реализации метода происходит вычисление результата

private:
    std::string* value;

};

