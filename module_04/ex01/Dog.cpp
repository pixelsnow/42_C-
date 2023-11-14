/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:12 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
}

Dog::Dog(const Dog &source) : Animal(source) {}

Dog::~Dog(void) {}

Dog &Dog::operator=(const Dog &source)
{
	this->type = source.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << "<< bark" << std::endl;
}
