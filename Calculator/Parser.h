#pragma once
#include "Calculatable.h"

class Parser
{
public:
	Parser();
	~Parser();

	Calculatable* stringToCalculatable(std::string expression);

private:
	bool isExpression(std::string expression);
	int getPositionOfNextOperation(std::string expression);
	std::string getLeftValue(std::string expression, int position);
	std::string getRightValue(std::string expression, int position);
	bool isValidNumber(std::string number);

};

