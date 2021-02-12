#pragma once
#include "Expression.h"
#include "Number.h"

class Parser
{
public:
	Parser();
	~Parser();

	Calculatable* stringToCalculatable(std::string* expression);
	std::string* deleteSpaces(std::string* expression);

private:
	std::string* getLeftValue(std::string* expression, int position);
	std::string* getRightValue(std::string* expression, int position);
	std::string* removeBracket(std::string* expression, int position);
};

