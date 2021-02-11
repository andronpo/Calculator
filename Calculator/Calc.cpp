#include <iostream>
#include "Parser.h"
#include "Calculator.h"

int main()
{
    std::cout.precision(2);
    std::string expression;
    std::cin >> expression;

    Parser* parser = new Parser();
    Calculatable* expressionTree = parser->stringToCalculatable(expression);
    Calculator* calculator = new Calculator();
    double result = calculator->calculate(expressionTree); 

    std::cout << std::fixed << result;
}
