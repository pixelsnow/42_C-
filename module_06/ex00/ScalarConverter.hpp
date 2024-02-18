#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>
#include <cctype>
#include <iomanip>
#include <limits>

enum CharType
{
	MINUS,
    DOT,
    F,
    DIGIT,
    INVALID_CHAR
};

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	MINUS_INF,
	PLUS_INF,
	NAN,
	INVALID
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &source);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &source);

		static CharType getCharType(char c);
		static Type detectSpecialType(std::string const literal);
		static Type detectNumericType(std::string const literal);
		static Type detectLiteralType(std::string const literal);


	public:
		static void convert (std::string const literal);
};

#endif
