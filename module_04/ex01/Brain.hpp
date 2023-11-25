/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Brain.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 16:21:39 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/25 18:39:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BRAIN_HPP
#define BRAIN_HPP

#include <iostream>
#include "colours.hpp"

class Brain
{
private:
	std::string ideas[100];

public:
	Brain(void);
	Brain(const Brain &source);
	~Brain(void);
	Brain &operator=(const Brain &source);

	// functions for testing
	void addIdea(std::string newIdea, int index);
	void printIdeas(void) const;
};

#endif