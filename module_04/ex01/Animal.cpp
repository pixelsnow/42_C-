/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Animal.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:54 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:31 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Animal.hpp"

Animal::Animal(void) : type("Animal") {}

Animal::Animal(const Animal &source) : type(source.type) {}

Animal::~Animal(void) {}

Animal &Animal::operator=(const Animal &source)
{
	this->type = source.type;
	return *this;
}

std::string Animal::getType(void) const
{
	return this->type;
}

void Animal::makeSound(void) const
{
	std::cout << "<< ???" << std::endl;
}