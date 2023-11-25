/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:54 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/25 15:06:30 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal")
{
	std::cout << GREEN << "Undefined Animal was born" << RESET << std::endl;
}

Animal::Animal(const Animal &source) : type(source.type)
{
	std::cout << GREEN << "Undefined Animal was created in the image of another Animal" << RESET << std::endl;
}

Animal::~Animal(void)
{
	std::cout << RED << "Undefined Animal died :(" << RESET << std::endl;
}

Animal &Animal::operator=(const Animal &source)
{
	this->type = source.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}