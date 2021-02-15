#include <iostream>
#include "Parser.h"
#include "Calculator.h"

int main()
{
    std::cout.precision(2);
    std::string* expression = new std::string();
    std::getline(std::cin, *expression);                                         //считывание выражения

    Parser* parser = new Parser();
    expression = parser->prepareExpression(expression);                         //удаление лишних пробелов и замена запятых на точки
    Calculatable* expressionTree = parser->stringToCalculatable(expression);    //парсер разбирает исходное выражение и возвращает дерево компановщика
    Calculator* calculator = new Calculator();

    double result = calculator->calculate(expressionTree);                      //вычисление результата от выражения
    expressionTree->clear();

    std::cout << std::fixed << result;
}
