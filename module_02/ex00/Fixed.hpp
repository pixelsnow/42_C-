/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/31 17:40:38 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int fractionalPart = 8;

public:
	Fixed(void);
	Fixed(const Fixed &source);

	~Fixed(void);

	Fixed &operator=(const Fixed &source);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
