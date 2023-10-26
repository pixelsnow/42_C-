/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Fixed.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:57:12 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/26 20:23:51 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FIXED_HPP
#define FIXED_HPP

#include <iostream>

class Fixed
{
private:
	int num;
	static const int bits = 8;

public:
	Fixed(void);
	Fixed(const Fixed &source);
	~Fixed(void);
	Fixed &operator=(Fixed &source);

	int getRawBits(void) const;
	void setRawBits(int const raw);
};

#endif
