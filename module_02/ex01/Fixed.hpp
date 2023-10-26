/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/26 21:11:07 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int num;
	static const int bits = 8; // should it be in constructors instead?

public:
	Fixed(void);
	Fixed(const Fixed &source);
	Fixed(const int value);
	Fixed(const float value);

	~Fixed(void);
	Fixed &operator=(Fixed &source);
	// std::ostream &operator<<(std::ostream &out);

	int getRawBits(void) const;
	void setRawBits(int const raw);
	/* float toFloat(void) const;
	int toInt(void) const; */
};

std::ostream &operator<<(std::ostream &out, const Fixed &fixed);

#endif
