#pragma once
#include "Calculatable.h"
class Number :
    public Calculatable
{
    Number();
    ~Number();
    Number(std::string value);

    virtual double calculate() override;

    std::string value;

};

