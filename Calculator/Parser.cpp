#include "Parser.h"

Parser::Parser()
{
}

Parser::~Parser()
{
}

Calculatable* Parser::stringToCalculatable(std::string* expression)
{
    int level = 0;
    int position = 0;
    for (int i = expression->size() - 1; i >= 0; --i) {     //поиск действия выполняющегося последним (+ и -)
        if (expression->at(i) == ')') {
            ++level;
            continue;
        }

        if (expression->at(i) == '(') {
            --level;
            continue;
        }

        if (level > 0) {
            continue;
        }

        if ((expression->at(i) == '+' || expression->at(i) == '-') && i != 0) { //разделение выражения
            std::string* left = getLeftValue(expression, i);
            std::string* right = getRightValue(expression, i);
            return new Expression(stringToCalculatable(left), stringToCalculatable(right), expression->at(i));
        }
    }

    for (int i = expression->size() - 1; i >= 0; --i) {     //поиск действия выполняющегося последним (* и /)
        if (expression->at(i) == ')') {
            ++level;
            continue;
        }

        if (expression->at(i) == '(') {
            --level;
            continue;
        }

        if (level > 0) {
            continue;
        }

        if (expression->at(i) == '*' || expression->at(i) == '/') {         //разделение выражения
            std::string* left = getLeftValue(expression, i);
            std::string* right = getRightValue(expression, i);
            return new Expression(stringToCalculatable(left), stringToCalculatable(right), expression->at(i));
        }
    }

    if (expression->at(0) == '(') {
        for (int i = 0; i < expression->size(); ++i) {
            if (expression->at(i) == '(') {
                ++level;
                continue;
            }

            if (expression->at(i) == ')') {
                --level;
                if (level == 0) {
                    return stringToCalculatable(removeBracket(expression, i));  //удаление внешних скобок
                }
                continue;
            }
        }
    }
    else {
        return new Number(expression);      //если ниодно из предыдущих условий не выполнилось, то это число
    }
    return NULL;
}

std::string* Parser::deleteSpaces(std::string* expression)
{
    std::string* result = new std::string();
    for (int i = 0; i < expression->size(); i++) {
        if (expression->at(i) != ' ') {
            result->push_back(expression->at(i));
        }
    }
    return result;
}

std::string* Parser::getLeftValue(std::string* expression, int position)
{
	return new std::string(expression->substr(0, position));
}

std::string* Parser::getRightValue(std::string* expression, int position)
{
	return new std::string(expression->substr(position + 1));
}

std::string* Parser::removeBracket(std::string* expression, int position)
{
    return new std::string(expression->substr(1, position - 1));
}
