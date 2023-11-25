/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.cpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:26:59 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/25 18:39:13 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Cat.hpp"

Cat::Cat(void)
{
	this->type = "Cat";
	this->brain = new Brain();
	std::cout << GREEN << "Cat was born" << RESET << std::endl;
}

Cat::Cat(const Cat &source) : Animal(source)
{
	this->brain = new Brain(*(source.brain));
	std::cout << GREEN << "Cat was created in the image of another Cat" << RESET << std::endl;
}

Cat::~Cat(void)
{
	delete this->brain;
	std::cout << RED << "Cat died :(" << RESET << std::endl;
}

Cat &Cat::operator=(const Cat &source)
{
	this->type = source.type;
	*(this->brain) = *(source.brain);
	return *this;
}

void Cat::makeSound(void) const
{
	std::cout << YELLOW << "<< meow" << RESET << std::endl;
}

void Cat::addIdea(std::string newIdea, int index)
{
	this->brain->addIdea(newIdea, index);
}

void Cat::printIdeas(void) const
{
	this->brain->printIdeas();
}