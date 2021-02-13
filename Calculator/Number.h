#pragma once
#include "Calculatable.h"
#include <stdexcept>
#include <iostream>

class Number :                              //���������� ��������� ���������
    public Calculatable
{
public:
    Number();
    ~Number();
    Number(std::string* value);

    virtual double calculate() override;    //� ���������� ������ ���������� ���������� ����������
    virtual void clear() override;

private:
    std::string* value;

};

