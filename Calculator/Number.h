#pragma once
#include "Calculatable.h"

class Number :                              //простейший компонент выражения
    public Calculatable
{
public:
    Number();
    ~Number();
    Number(std::string* value);

    virtual double calculate() override;    //в реализации метода происходит вычисление результата
    virtual void clear() override;

private:
    std::string* value;

};

