/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongAnimal.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:38:45 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 18:44:53 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongAnimal.hpp"

WrongAnimal::WrongAnimal(void) : type("WrongAnimal")
{
	std::cout << GREEN << "Wrong undefined Animal was born" << RESET << std::endl;
}

WrongAnimal::WrongAnimal(const WrongAnimal &source) : type(source.type)
{
	std::cout << GREEN << "Wrong Undefined Animal was created in the image of another Wrong Animal" << RESET << std::endl;
}

WrongAnimal::~WrongAnimal(void)
{
	std::cout << RED << "Wrong Undefined Animal died :(" << RESET << std::endl;
}

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
	std::cout << "<< Wrong Undefined Animal sound" << std::endl;
}