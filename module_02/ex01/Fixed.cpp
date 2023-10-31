/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:11 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/31 17:58:58 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

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
	std::cout << "Int constructor called on " << value << std::endl;

	try
	{
		if (value < -8388608 || value > 8388607)
			throw(1);
		else
			this->rawBits = value << this->fractionalPart;
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
			this->rawBits = static_cast<int>(std::roundf(value * (1 << this->fractionalPart)));
	}
	catch (int e)
	{
		std::cout << "ERROR: Value " << value << " out of range [-8388608; 8388607]" << std::endl;
	}
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = source.rawBits;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	/* UNCOMMENT TO SEE BINARY REPRESENTATION */

	/* std::bitset<32> a(fixed.getRawBits());
	out << "= [" << a << "]";
	out << " = "; */

	out << fixed.toFloat();
	return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return this->rawBits;
}

void Fixed::setRawBits(int const raw)
{
	this->rawBits = raw;
}

float Fixed::toFloat(void) const
{
	return (static_cast<float>(this->rawBits) / static_cast<float>(1 << this->fractionalPart));
}

int Fixed::toInt(void) const
{
	return this->rawBits >> this->fractionalPart;
}