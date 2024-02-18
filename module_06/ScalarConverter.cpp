#include "ScalarConverter.hpp"

ScalarConverter::ScalarConverter() {}

ScalarConverter::ScalarConverter(ScalarConverter const &source) {}

ScalarConverter::~ScalarConverter() {}

ScalarConverter &ScalarConverter::operator=(ScalarConverter const &source)
{
	return (*this);
}

CharType getCharType(char c) {
	if (c == '-') return MINUS;
	if (c == '.') return DOT;
	if (c == 'f') return F;
	if (std::isdigit(c)) return DIGIT;
	return INVALID_CHAR;
}

Type detectSpecialType(std::string const literal)
{
	if (literal.length() == 3 && literal[0] == '’' && literal[2] == '’')
		return CHAR;
	else if (literal == "-inf")
		return MINUS_INF;
	else if (literal == "+inf")
		return PLUS_INF;
	else if (literal == "-inff")
		return MINUS_INF_FLOAT;
	else if (literal == "+inff")
		return MINUS_INF_FLOAT;
	else if (literal == "nan")
		return NAN;
	else if (literal == "nanf")
		return NAN_FLOAT;
	return (INVALID);
}

Type detectNumericType(std::string const literal)
{
	bool dot = false;
	for (std::size_t i = 0; i < literal.length(); i++)
	{
		CharType charType = getCharType(literal[i]);
		switch (charType) {
			// minus is only OK once as a first character
			case MINUS:
				if (i !=  0) return INVALID;
				break;
			// dot is only OK once
			case DOT:
				if (dot) return INVALID;
				dot = true;
				break;
			// f is only OK once as a last character
			case F:
				if (!dot || i != literal.length() -  1) return INVALID;
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

Type detectLiteralType(std::string const literal)
{
	Type res = detectSpecialType(literal);
	if (res != INVALID)
		return res;
	return detectNumericType(literal);
}

void ScalarConverter::convert (std::string const literal)
{
	Type literalType = detectLiteralType(literal);
	std::cout << "char : " << static_cast<char>(5) << std::endl;
}
