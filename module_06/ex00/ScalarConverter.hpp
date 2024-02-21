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

		static void printStringValue(std::string typeName,
			std::string stringValue);
		static void printConversionsStrings(std::string charValue,
			std::string intValue, std::string floatValue,
			std::string doubleValue);
		static void printCharValue(char charValue);
		static void printIntValue(int intValue);
		static void printFloatValue(float floatValue);
		static void printDoubleValue(double doubleValue);

		static void convertInvalid();
		static void convertPlusInf();
		static void convertMinusInf();
		static void convertNaN();
		static void convertChar(std::string const literal);
		static void convertInt(std::string const literal);
		static void convertFloat(std::string const literal);
		static void convertDouble(std::string const literal);

	public:
		static void convert (std::string const literal);
};

#endif
