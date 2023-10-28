/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:11 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/28 16:41:25 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : rawBits(0) // TODO: change
{
	std::cout << "Default constructor called" << std::endl;
}

// Should I remove getRawBits() to match the example output better?
Fixed::Fixed(const Fixed &source) : rawBits(source.rawBits)
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : rawBits(value << fractionalPart)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value) : rawBits(static_cast<int>(std::roundf(value * (1 << this->fractionalPart))))
{
	std::cout << "Float constructor called" << std::endl;

	/* int rawBits;
	memcpy(&rawBits, &value, sizeof(int));

	std::bitset<32> a(rawBits);
	std::cout << "Float constructor value: " << value << "	= [" << a << "]" << std::endl;

	std::bitset<32> b(value * (1 << this->fractionalPart));
	std::cout << "Before rounding: " << value * (1 << this->fractionalPart) << "	= [" << b << "]" << std::endl;

	std::bitset<32> c(std::roundf(value * (1 << this->fractionalPart)));
	std::cout << "After rounding: " << std::roundf(value * (1 << this->fractionalPart)) << "	= [" << c << "]" << std::endl;

	std::bitset<32> d(static_cast<int>(std::roundf(value * (1 << this->fractionalPart))));
	std::cout << "After casting: " << static_cast<int>(std::roundf(value * (1 << this->fractionalPart))) << "	= [" << d << "]" << std::endl; */

	// setRawBits(static_cast<int>(std::roundf(value * (1 << this->fractionalPart))));
	/* std::cout << "After: " << *this << std::endl; */

	// this->num =
}

Fixed &Fixed::operator=(const Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->rawBits = source.rawBits;
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
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
	std::cout << "getRawBits member function called" << std::endl;
	return rawBits;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
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