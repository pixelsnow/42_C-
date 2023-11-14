/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:59 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 18:45:54 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	std::cout << GREEN << "Cat was born" << RESET << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source)
{
	std::cout << GREEN << "Cat was created in the image of another Cat" << RESET << std::endl;
}

Cat::~Cat(void)
{
	std::cout << RED << "Cat died :(" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
	this->type = source.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "<< meow" << RESET << std::endl;
}
