/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:11 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/26 21:41:41 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"

Fixed::Fixed(void) : num(0)
{
	std::cout << "Default constructor called" << std::endl;
}

// Should I remove getRawBits() to match the example output better?
Fixed::Fixed(const Fixed &source) : num(source.getRawBits())
{
	std::cout << "Copy constructor called" << std::endl;
}

Fixed::Fixed(const int value) : num(value << fractionalPart)
{
	std::cout << "Int constructor called" << std::endl;
}

Fixed::Fixed(const float value)
{
	std::cout << "Int constructor called" << std::endl;
	// this->num =
}

Fixed &Fixed::operator=(Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = source.getRawBits();
	return *this;
}

std::ostream &operator<<(std::ostream &out, const Fixed &fixed)
{
	std::bitset<32> a(fixed.getRawBits());
	out << "[" << a << "]";
	out << " = " << fixed.toInt();
	/* float test = 10.5;
	std::bitset<32> b(test);
	out << "[" << b << "]"; */
	return out;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	return num;
}

void Fixed::setRawBits(int const raw)
{
	num = raw;
}

float Fixed::toFloat(void) const
{
	float res;
	res = 0;
	return res;
}

int Fixed::toInt(void) const
{
	return this->getRawBits() >> this->fractionalPart;
}