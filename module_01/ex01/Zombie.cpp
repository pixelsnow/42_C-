/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Zombie.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:53:29 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/24 17:50:14 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie::Zombie(void){};

Zombie::Zombie(std::string newName) : name(newName){};

Zombie::~Zombie(void)
{
	std::cout << "Zombie " << name << " is being destroyed... :(" << std::endl;
};

void Zombie::setName(std::string newName)
{
	name = newName;
}

void Zombie::announce(void) const
{
	std::cout << name << ": BraiiiiiiinnnzzzZ..." << std::endl;
}