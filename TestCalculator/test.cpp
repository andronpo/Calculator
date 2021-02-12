#include "pch.h"
#include "../Calculator/Expression.h"
#include "../Calculator/Parser.h"
#include "../Calculator/Number.h"


TEST(CheckingParser, checkPreparingSimple) {
	Parser* parser = new Parser();
	std::string* stringNumber = new std::string("  4,2");
	std::string* number = parser->prepareExpression(stringNumber);
	std::string otherNumber = "4.2";
	EXPECT_EQ(*number, otherNumber);
	EXPECT_TRUE(true);
}

TEST(CheckingParser, checkPreparingExpression) {
	Parser* parser = new Parser();
	std::string* stringNumber = new std::string("-4 * (      5.6 -5) *  4,2");
	std::string* number = parser->prepareExpression(stringNumber);
	std::string otherNumber = "-4*(5.6-5)*4.2";
	EXPECT_EQ(*number, otherNumber);
	EXPECT_TRUE(true);
}

TEST(CheckingCalculation, checkNumber) {
	std::string* stringNumber = new std::string("4.2");
	Number* number = new Number(stringNumber);
	double otherNumber = 4.2;
	EXPECT_EQ(number->calculate(), otherNumber);
	EXPECT_TRUE(true);
}

TEST(CheckingCalculation, checkExpression) {
	std::string* stringNumber = new std::string("2");
	Number* number = new Number(stringNumber);
	Expression* expression = new Expression(number, number, '*');
	double otherNumber = 4;
	EXPECT_EQ(expression->calculate(), otherNumber);
	EXPECT_TRUE(true);
}