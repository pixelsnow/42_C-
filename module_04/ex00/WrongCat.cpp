/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:38:51 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 16:08:50 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source) {}

WrongCat::~WrongCat(void) {}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	this->type = source.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << "<< wrong meow" << std::endl;
}
