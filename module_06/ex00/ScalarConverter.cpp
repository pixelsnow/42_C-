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

// TYPE DETECTION

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
	if (!literal.length())
		return INVALID;
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

// PRINTING

void ScalarConverter::printStringValue(std::string typeName,
	std::string stringValue)
{
	std::cout << typeName << ": " << stringValue << std::endl;
}

void ScalarConverter::printConversionsStrings(std::string charValue,
	std::string intValue, std::string floatValue, std::string doubleValue)
{
	printStringValue("char", charValue);
	printStringValue("int", intValue);
	printStringValue("float", floatValue);
	printStringValue("double", doubleValue);
}

void ScalarConverter::printCharValue(char charValue)
{
	if (std::isprint(charValue))
		std::cout << "char: " << "\'" << charValue << "\'" << std::endl;
	else
		printStringValue("char", "Non displayable");
}

void ScalarConverter::printIntValue(int intValue)
{
	std::cout << "int: " << intValue << std::endl;
}

void ScalarConverter::printFloatValue(float floatValue)
{
	std::cout << "float: " << std::fixed << std::setprecision(1) << floatValue
		<< "f" << std::endl;
}

void ScalarConverter::printDoubleValue(double doubleValue)
{
	std::cout << "double: " << std::fixed << std::setprecision(1)
		<< doubleValue << std::endl;
}

// CONVERTERS

void ScalarConverter::convertInvalid()
{
	std::cout << "Not a valid literal" << std::endl;
}

void ScalarConverter::convertPlusInf()
{
	printConversionsStrings("impossible", "impossible", "+inff", "+inf");
}

void ScalarConverter::convertMinusInf()
{
	printConversionsStrings("impossible", "impossible", "-inff", "-inf");
}

void ScalarConverter::convertNaN()
{
	printConversionsStrings("impossible", "impossible", "nanf", "nan");
}

void ScalarConverter::convertChar(std::string const literal)
{
	char c = literal[1];
	printCharValue(c);
	printIntValue(static_cast<int>(c));
	printFloatValue(static_cast<float>(c));
	printDoubleValue(static_cast<double>(c));
}

void ScalarConverter::convertInt(std::string const literal)
{
	try
	{
		int num;
		num = std::stoi(literal);

		if (num < std::numeric_limits<char>::min()
			|| num > std::numeric_limits<char>::max())
			printStringValue("char", "impossible");
		else
			printCharValue(static_cast<char>(num));

		printIntValue(num);
		printFloatValue(static_cast<float>(num));
		printDoubleValue(static_cast<double>(num));
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to int. " << e.what()
			<< std::endl;
	}
}

void ScalarConverter::convertFloat(std::string const literal)
{
	try
	{
		float num;
		num = std::stof(literal);

		if (num < std::numeric_limits<char>::min()
			|| num > std::numeric_limits<char>::max())
			printStringValue("char", "impossible");
		else
			printCharValue(static_cast<char>(num));

		if (num < std::numeric_limits<int>::lowest()
			|| num > std::numeric_limits<int>::max())
			printStringValue("int", "impossible");
		else
			printIntValue(static_cast<int>(num));

		printFloatValue(num);
		printDoubleValue(static_cast<double>(num));
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to float. "
			<< e.what() << std::endl;
	}
}

void ScalarConverter::convertDouble(std::string const literal)
{
	try
	{
		double num;
		num = std::stod(literal);

		if (num < std::numeric_limits<char>::min()
			|| num > std::numeric_limits<char>::max())
			printStringValue("char", "impossible");
		else
			printCharValue(static_cast<char>(num));

		if (num < std::numeric_limits<int>::lowest()
			|| num > std::numeric_limits<int>::max())
			printStringValue("int", "impossible");
		else
			printIntValue(static_cast<int>(num));

		if (num < std::numeric_limits<float>::lowest()
			|| num > std::numeric_limits<float>::max())
			printStringValue("float", "impossible");
		else
			printFloatValue(static_cast<float>(num));

		printDoubleValue(num);
	}
	catch(const std::exception &e)
	{
		std::cout << "Could not convert " << literal << " to double. "
			<< e.what() << std::endl;
	}
}

void ScalarConverter::convert (std::string const literal)
{
	Type literalType = detectLiteralType(literal);
	switch (literalType)
	{
		case INVALID:
			convertInvalid();
			break;
		case PLUS_INF:
			convertPlusInf();
			break;
		case MINUS_INF:
			convertMinusInf();
			break;
		case NAN:
			convertNaN();
			break;
		case CHAR:
			convertChar(literal);
			break;
		case INT:
			convertInt(literal);
			break;
		case FLOAT:
			convertFloat(literal);
			break;
		case DOUBLE:
			convertDouble(literal);
	}
}
