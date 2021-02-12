#include <iostream>
#include "Parser.h"
#include "Calculator.h"

int main()
{
    std::cout.precision(2);
    std::string* expression = new std::string();
    std::getline(std::cin, *expression);                                         //считывание выражения

    Parser* parser = new Parser();
    expression = parser->deleteSpaces(expression);                              //удаление лишних пробелов
    Calculatable* expressionTree = parser->stringToCalculatable(expression);    //парсер разбирает исходное выражение и возвращает дерево компановщика
    Calculator* calculator = new Calculator();

    double result = calculator->calculate(expressionTree);                      //вычисление результата от выражения

    std::cout << std::fixed << result;
}
