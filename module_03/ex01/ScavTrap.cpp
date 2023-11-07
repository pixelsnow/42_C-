/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:44:57 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 20:17:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

ScavTrap::ScavTrap(std::string newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 50;
	this->attackDamage = 20;
	std::cout << CYAN << "ScavTrap " << newName << " is created" << RESET << std::endl;
}

ScavTrap::ScavTrap(const ScavTrap &source)
	: ClapTrap(source)
{
	std::cout << MAGENTA << "ScavTrap " << this->name << " is created in the image of ScavTrap " << source.name << RESET << std::endl;
}

ScavTrap &ScavTrap::operator=(const ScavTrap &source)
{
	std::cout << MAGENTA << "ScavTrap " << this->name << " is being turned into a clone of ScavTrap " << source.name << RESET << std::endl;
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	return *this;
}

void ScavTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << RED << "ScavTrap " << this->name << " unsuccessfully tries to attack " << target << RESET << std::endl;
		return;
	}
	std::cout << "ScavTrap " << this->name << " attacks " << target << ", causing " << this->attackDamage << " points of damage" << std::endl;
	this->energyPoints--;
}

ScavTrap::~ScavTrap(void)
{
	std::cout << CYAN << "ScavTrap " << this->name << " is destroyed" << RESET << std::endl;
}

void ScavTrap::guardGate(void) const
{
	std::cout << CYAN << "ScavTrap " << this->name << " is now in Gate keeper mode" << RESET << std::endl;
}