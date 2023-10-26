/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:11 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/26 20:33:15 by vvagapov         ###   ########.fr       */
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

Fixed &Fixed::operator=(Fixed &source)
{
	std::cout << "Copy assignment operator called" << std::endl;
	this->num = source.getRawBits();
	return *this;
}

Fixed::~Fixed(void)
{
	std::cout << "Destructor called" << std::endl;
}

int Fixed::getRawBits(void) const
{
	std::cout << "getRawBits member function called" << std::endl;
	return num;
}

void Fixed::setRawBits(int const raw)
{
	std::cout << "setRawBits member function called" << std::endl;
	num = raw;
}