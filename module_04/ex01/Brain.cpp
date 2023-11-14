/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:21:34 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 17:17:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Brain.hpp"

Brain::Brain(void) {}

Brain::Brain(const Brain &source)
{
	for (int i=0; i<100; i++)
		this->ideas[i] = source.ideas[i];
}

Brain::~Brain(void) {}

Brain &Brain::operator=(const Brain &source)
{
	for (int i=0; i<100; i++)
		this->ideas[i] = source.ideas[i];
	return *this;
}