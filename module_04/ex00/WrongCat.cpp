/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   WrongCat.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:38:51 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 18:45:54 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "WrongCat.hpp"

WrongCat::WrongCat(void)
{
	this->type = "WrongCat";
	std::cout << GREEN << "Wrong Cat was born" << RESET << std::endl;
}

WrongCat::WrongCat(const WrongCat &source) : WrongAnimal(source)
{
	std::cout << GREEN << "Wrong Cat was created in the image of another Wrong Cat" << RESET << std::endl;
}

WrongCat::~WrongCat(void)
{
	std::cout << RED << "Cat died :(" << RESET << std::endl;
}

WrongCat &WrongCat::operator=(const WrongCat &source)
{
	this->type = source.type;
	return *this;
}

void WrongCat::makeSound(void) const
{
	std::cout << YELLOW << "<< Wrong meow" << RESET << std::endl;
}
