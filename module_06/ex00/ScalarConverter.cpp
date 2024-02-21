#include "ScalarConverter.hpp"

// CONSTRUCTORS

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &source)
{
	(void) source;
}

// DESTRUCTOR

ScalarConverter::~ScalarConverter() {}

// OPERATORS

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &source)
{
	(void) source;
	return (*this);
}

// MEMBER FUNCTIONS

Type ScalarConverter::detectSpecialType(std::string const literal)
{
	if (literal.length() == 3 && literal[0] == '\'' && literal[2] == '\'')
		return CHAR;
	else if (literal == "-inf" || literal == "-inff")
		return MINUS_INF;
	else if (literal == "+inf" || literal == "+inff")
		return PLUS_INF;
	else if (literal == "nan" || literal == "nanf")
		return NAN;
	return INVALID;
}

CharType ScalarConverter::getCharType(char c)
{
	if (c == '-') return MINUS;
	if (c == '.') return DOT;
	if (c == 'f') return F;
	if (std::isdigit(c)) return DIGIT;
	return INVALID_CHAR;
}

Type ScalarConverter::detectNumericType(std::string const literal)
{
	bool dot = false;
	for (std::size_t i = 0; i < literal.length(); i++)
	{
		CharType charType = getCharType(literal[i]);
		switch (charType)
		{
			// minus is only OK once as the first character
			case MINUS:
				if (i !=  0)
					return INVALID;
				break;
			// dot is only OK once
			case DOT:
				if (dot)
					return INVALID;
				dot = true;
				break;
			// f is only OK once as the last character
			case F:
				if (!dot || i != literal.length() -  1)
					return INVALID;
				return FLOAT;
			case DIGIT:
				break;
			case INVALID_CHAR:
				return INVALID;
		}
	}
	if (dot)
		return DOUBLE;
	return INT;
}

Type ScalarConverter::detectLiteralType(std::string const literal)
{
	Type res = detectSpecialType(literal);
	if (res != INVALID)
		return res;
	return detectNumericType(literal);
}

void printInvalid()
{
	std::cout << "Not a valid literal" << std::endl;
}

void printConversions(std::string charValue, std::string intValue, std::string floatValue, std::string doubleValue)
{
	std::cout << "char: " << charValue << std::endl;
	std::cout << "int: " << intValue << std::endl;
	std::cout << "float: " << floatValue << std::endl;
	std::cout << "double: " << doubleValue << std::endl;
}

void printPlusInf()
{
	printConversions("impossible", "impossible", "+inff", "+inf");
}

void printMinusInf()
{
	printConversions("impossible", "impossible", "-inff", "-inf");
}

void printNaN()
{
	printConversions("impossible", "impossible", "nanf", "nan");
}

void printChar(std::string const literal)
{
	char c = literal[1];
	std::string charValue;
	if (!std::isprint(c))
		charValue = "Non-displayable";
	else
		charValue = literal;
	std::cout << "char: " << charValue << std::endl;
	std::cout << "int: " << static_cast<int>(c) << std::endl;
	std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(c) << "f" << std::endl;
	std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(c) << std::endl;
}

void printInt(std::string const literal)
{
	try
	{
		int num;
		num = std::stoi(literal);
		if (num < std::numeric_limits<char>::min() || num > std::numeric_limits<char>::max())
			std::cout << "char: " << "impossible" << std::endl;
		else
			std::cout << "char: " << "\'" << static_cast<char>(num) << "\'" << std::endl;
		std::cout << "int: " << num << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << static_cast<float>(num) << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to int" << std::endl;
	}
}

void printFloat(std::string const literal)
{
	try
	{
		int num;
		num = std::stof(literal);
		std::cout << "char: " << static_cast<char>(num) << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to float" << std::endl;
	}
}

void printDouble(std::string const literal)
{
	try
	{
		int num;
		num = std::stod(literal);
		std::cout << "char: " << static_cast<char>(num) << std::endl;
		std::cout << "int: " << static_cast<int>(num) << std::endl;
		std::cout << "float: " << std::fixed << std::setprecision(1) << num << "f" << std::endl;
		std::cout << "double: " << std::fixed << std::setprecision(1) << static_cast<double>(num) << std::endl;
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to double" << std::endl;
	}
}

const char* getTypeString(Type type) {
	switch (type) {
		case CHAR:
			return "CHAR";
		case INT:
			return "INT";
		case FLOAT:
			return "FLOAT";
		case DOUBLE:
			return "DOUBLE";
		case MINUS_INF:
			return "MINUS_INF";
		case PLUS_INF:
			return "PLUS_INF";
		case NAN:
			return "NAN";
		case INVALID:
			return "INVALID";
	}
}

void ScalarConverter::convert (std::string const literal)
{
	Type literalType = detectLiteralType(literal);
	std::cout << "type detected: " << getTypeString(literalType) << std::endl;
	switch (literalType)
	{
		case INVALID:
			printInvalid();
			break;
		case PLUS_INF:
			printPlusInf();
			break;
		case MINUS_INF:
			printMinusInf();
			break;
		case NAN:
			printNaN();
			break;
		case CHAR:
			printChar(literal);
			break;
		case INT:
			printInt(literal);
			break;
		case FLOAT:
			printFloat(literal);
			break;
		case DOUBLE:
			printDouble(literal);
	}
}
