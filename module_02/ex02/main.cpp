/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 20:50:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/30 20:49:43 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Fixed.hpp"
#include <iostream>

void test(const Fixed &a, const Fixed &b)
{
	std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a != b: " << (a != b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "a < b: " << (a < b) << std::endl;
	std::cout << "a >= b: " << (a >= b) << std::endl;
	std::cout << "a <= b: " << (a <= b) << std::endl;
	std::cout << std::endl;
}

int main(void)
{
	Fixed const a(100);
	Fixed const b(-10);
	test(a, b);
	Fixed const c(42.42f);
	Fixed const d(42.1f);
	test(c, d);
	Fixed const e(0);
	Fixed const f(0.1f);
	test(e, f);
	Fixed const g(-10.005f);
	Fixed const h(-10.5f);
	test(g, h);
	Fixed const i(-10.0f);
	Fixed const j(-10.0f);
	test(i, j);
	Fixed const k(-10);
	Fixed const l(10);
	test(k, l);
	/* std::cout << "a is " << a << std::endl;
	std::cout << "b is " << b << std::endl;
	std::cout << "a == b: " << (a == b) << std::endl;
	std::cout << "a > b: " << (a > b) << std::endl;
	std::cout << "c is " << c << std::endl;
	std::cout << "d is " << d << std::endl;
	std::cout << "e is " << e << std::endl;
	std::cout << "f is " << f << std::endl;
	std::cout << "g is " << g << std::endl;
	std::cout << "h is " << h << std::endl; */
	return 0;
}