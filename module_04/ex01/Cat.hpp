/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:02 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 19:57:42 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "Brain.hpp"
#include "colours.hpp"

class Cat : public Animal
{
private:
	Brain *brain;

public:
	Cat(void);
	Cat(const Cat &source);
	~Cat(void);

	Cat &operator=(const Cat &source);

	void makeSound(void) const;
};

#endif