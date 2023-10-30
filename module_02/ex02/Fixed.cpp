/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:49:53 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/30 22:01:48 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

/* CONSTRUCTORS */

Fixed::Fixed(void) : rawBits(0)
{
	std::cout << "Default constructor called" << std::endl;
}

Fixed::Fixed(const Fixed &source) : rawBits(source.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value)
{
	std::cout << "Int constructor called" << std::endl;

	try
	{
		if (value < -8388608 || value > 8388607)
			throw(1);
		else
			rawBits = value << fractionalPart;
	}
	catch (int e)
	{
		std::cout << "ERROR: Value " << value << " out of range [-8388608; 8388607]" << std::endl;
	}
}

Fixed::Fixed(const float value)
{
	std::cout << "Float constructor called on " << value << std::endl;

	try
	{
		if (value < -8388608 || value > 8388607)
			throw(1);
		else
			rawBits = static_cast<int>(std::roundf(value * (1 << this->fractionalPart)));
	}
	catch (int e)
	{
		std::cout << "ERROR: Value " << value << " out of range [-8388608; 8388607]" << std::endl;
	}
}

/* COMPARISON OPERATORS */

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = source.rawBits;
	return *this;
}

bool Fixed::operator==(const Fixed &other) const
{
	return other.rawBits == this->rawBits;
}

bool Fixed::operator!=(const Fixed &other) const
{
	return other.rawBits != this->rawBits;
}

bool Fixed::operator>(const Fixed &other) const
{
	return (this->rawBits > other.rawBits);
}

bool Fixed::operator<(const Fixed &other) const
{
	return (this->rawBits < other.rawBits);
}

bool Fixed::operator>=(const Fixed &other) const
{
	return (this->rawBits >= other.rawBits);
}

bool Fixed::operator<=(const Fixed &other) const
{
	return (this->rawBits <= other.rawBits);
}

/* ARITHMETIC OPERATORS */

Fixed Fixed::operator+(const Fixed &other) const
{
	Fixed res;
	res.rawBits = this->rawBits + other.rawBits;
	return res;
}

Fixed Fixed::operator-(const Fixed &other) const
{
	Fixed res;
	res.rawBits = this->rawBits - other.rawBits;
	return res;
}

// TODO: check
Fixed Fixed::operator*(const Fixed &other) const
{
	Fixed res;
	int multiplied = static_cast<int64_t>(this->rawBits * other.rawBits);
	res.rawBits = (multiplied >> this->fractionalPart) + ((multiplied >> (this->fractionalPart - 1)) & 1);
	return res;
}

Fixed Fixed::operator/(const Fixed &other) const
{
	Fixed res;
	int divided = static_cast<int64_t>(this->rawBits / other.rawBits);
	res.rawBits = (divided >> this->fractionalPart) + ((divided >> (this->fractionalPart - 1)) & 1);
	return res;
}

/* INCREMENT/DECREMENT OPERATORS */

Fixed &Fixed::operator++(void)
{
	++rawBits;
	return *this;
}

Fixed &Fixed::operator--(void)
{
	--rawBits;
	return *this;
}

Fixed Fixed::operator++(int)
{
	Fixed original(*this);
	rawBits++;
	return original;
}

Fixed Fixed::operator--(int)
{
	Fixed original(*this);
	rawBits--;
	return original;
}

/* OUTPUT OPERATOR */

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	/* UNCOMMENT TO SEE BINARY REPRESENTATION */

	std::bitset<32> a(fixed.getRawBits());
	out << "= [" << a << "]";
	out << " = ";

	out << fixed.toFloat();
	return out;
}

/* DESTRUCTOR */

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

/* MEMBER FUNCTIONS */

int Fixed::getRawBits(void) const
{
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / static_cast<float>(1 << this->fractionalPart));
}

int Fixed::toInt(void) const
{
	return this->rawBits >> this->fractionalPart;
}