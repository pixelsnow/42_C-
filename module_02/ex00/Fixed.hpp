/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/28 16:33:42 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int rawBits;
	static const int fractionalPart = 8; // should it be in constructors instead?

public:
	Fixed(void);
	Fixed(const Fixed &source);
	~Fixed(void);

	Fixed &operator=(const Fixed &source);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
