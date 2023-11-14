/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Dog.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:06 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 19:29:57 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef DOG_HPP
#define DOG_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "colours.hpp"

class Dog : public Animal
{
private:
	Brain *brain;

public:
	Dog(void);
	Dog(const Dog &source);
	~Dog(void);

	Dog &operator=(const Dog &source);

	void makeSound(void) const;
};

#endif