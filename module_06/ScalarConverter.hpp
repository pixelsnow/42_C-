#ifndef SCALAR_CONVERTER_HPP
#define SCALAR_CONVERTER_HPP

#include <iostream>

enum Type
{
	CHAR,
	INT,
	FLOAT,
	DOUBLE,
	MINUS_INF,
	PLUS_INF,
	NAN,
	MINUS_INF_FLOAT,
	PLUS_INF_FLOAT,
	NAN_FLOAT
};

class ScalarConverter
{
	private:
		ScalarConverter();
		ScalarConverter(ScalarConverter const &source);
		~ScalarConverter();

		ScalarConverter &operator=(ScalarConverter const &source);

	public:
		static void convert (std::string const literal);
};

#endif
