/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:21:34 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/24 20:27:59 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {}

Brain::Brain(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];
}

Brain::~Brain(void) {}

Brain &Brain::operator=(const Brain &source)
{
	for (int i = 0; i < 100; i++)
		this->ideas[i] = source.ideas[i];
	return *this;
}

void Brain::addIdea(std::string newIdea, int index)
{
	if (index < 0 || index >= 100)
		return;
	this->ideas[index] = newIdea;
}

void Brain::printIdeas(void) const
{
	std::cout << "Brain contents:" << std::endl;
	for (int i = 0; i < 100; i++)
	{
		if (this->ideas[i].length())
			std::cout << "[" << i << "] " << this->ideas[i] << std::endl;
	}
}