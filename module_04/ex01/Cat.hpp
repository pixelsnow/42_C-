/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Cat.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 17:27:02 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 17:37:36 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CAT_HPP
#define CAT_HPP

#include <iostream>
#include "Animal.hpp"
#include "colours.hpp"

class Cat : public Animal
{
public:
	Cat(void);
	Cat(const Cat &source);
	~Cat(void);

	Cat &operator=(const Cat &source);

	void makeSound(void) const;
};

#endif