/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:39:29 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 13:41:25 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "HumanB.hpp"

HumanB::HumanB(std::string newName)
	: name(newName), weapon(NULL) {}

HumanB::~HumanB(void)
{
	if (weapon != NULL)
		delete (weapon);
}

void HumanB::attack(void) const
{
	std::cout << name << " attacks";
	if (weapon)
		std::cout << " with their " << weapon->getType();
	std::cout << std::endl;
}

void HumanB::setWeapon(Weapon &newWeapon)
{
	weapon = &newWeapon;
}