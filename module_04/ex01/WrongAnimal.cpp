/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:38:45 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:01 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal") {}

WrongAnimal::WrongAnimal(const WrongAnimal &source) : type(source.type) {}

WrongAnimal::~WrongAnimal(void) {}

WrongAnimal &WrongAnimal::operator=(const WrongAnimal &source)
{
	this->type = source.type;
	return *this;
}

std::string WrongAnimal::getType(void) const
{
	return this->type;
}

void WrongAnimal::makeSound(void) const
{
	std::cout << "<< wrong ???" << std::endl;
}