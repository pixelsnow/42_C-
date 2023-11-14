/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 17:34:02 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	std::cout << GREEN << "Dog was born" << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source)
{
	std::cout << GREEN << "Dog was created in the image of another Dog" << RESET << std::endl;
}

Dog::~Dog(void)
{
	std::cout << RED << "Dog died :(" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
	this->type = source.type;
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "<< bark" << RESET << std::endl;
}
