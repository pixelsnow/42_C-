/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 19:29:33 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Dog.hpp"

Dog::Dog(void)
{
	this->type = "Dog";
	this->brain = new Brain();
	std::cout << GREEN << "Dog was born" << RESET << std::endl;
}

Dog::Dog(const Dog &source) : Animal(source)
{
	this->brain = new Brain(*(source.brain));
	std::cout << GREEN << "Dog was created in the image of another Dog" << RESET << std::endl;
}

Dog::~Dog(void)
{
	delete (this->brain);
	std::cout << RED << "Dog died :(" << RESET << std::endl;
}

Dog &Dog::operator=(const Dog &source)
{
	this->type = source.type;
	*(this->brain) = *(source.brain);
	return *this;
}

void Dog::makeSound(void) const
{
	std::cout << YELLOW << "<< bark" << RESET << std::endl;
}
