/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:59 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 16:09:20 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
}

Cat::Cat(const Cat &source) : Animal(source) {}

Cat::~Cat(void) {}

Cat &Cat::operator=(const Cat &source)
{
	this->type = source.type;
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << "<< meow" << std::endl;
}
