/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/04 20:08:38 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap(std::string newName)
	: name(newName), hitPoints(10), energyPoints(10), attackDamage(0) {}

ClapTrap::ClapTrap(const ClapTrap &source)
	: name(source.name), hitPoints(source.hitPoints),
	  energyPoints(source.energyPoints), attackDamage(source.attackDamage) {}

/* DESTRUCTOR */

ClapTrap::~ClapTrap(void) {}

/* OPERATORS */
ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	return *this;
}

/* MEMBER FUNCTIONS */

void ClapTrap::printTombstone(void) const
{
	std::cout << std::endl
			  << "      ,-=-." << std::endl;
	std::cout << "     /  +  \\" << std::endl;
	std::cout << "     | ~~~ |" << std::endl;
	std::cout << "     |R.I.P|" << std::endl;
	std::cout << "\\vV,,|_____|V,v/," << std::endl
			  << std::endl;
}

void ClapTrap::printGhost(void) const
{
	std::cout << std::endl
			  << " .-." << std::endl;
	std::cout << "(o o) boo!" << std::endl;
	std::cout << "| O \\" << std::endl;
	std::cout << " \\   \\" << std::endl;
	std::cout << "  `~~~'" << std::endl
			  << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " unsuccessfully tries to attack " << target << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ",causing " << this->attackDamage << " points of damage" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		std::cout << "Stop attacking the corpse of " << this->name << " pls" << std::endl
				  << std::flush;
		usleep(500000);
		printGhost();
		std::cout << std::flush;
		usleep(500000);
		std::cout << "That's right, asshole. You're being haunted now." << std::endl;
	}
	else if (amount > this->hitPoints)
	{
		this->hitPoints = 0;

		std::cout << "ClapTrap " << this->name << " dies after taking " << amount << " points of damage..." << std::endl
				  << std::flush;
		usleep(500000);
		printTombstone();
	}
	else
	{
		this->hitPoints -= amount;

		std::cout << "ClapTrap " << this->name << " takes " << amount << " points of damage and has only " << this->hitPoints << " points left now" << std::endl;
	}
}

void ClapTrap::beRepaired(unsigned int amount)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << "ClapTrap " << this->name << " unsuccessfully tries to repair itself :(" << std::endl;
		return;
	}

	hitPoints += amount;
	this->energyPoints--;

	std::cout << "ClapTrap " << this->name << " repairs itself by " << amount << " points, now " << this->name << "'s hit point count is " << this->hitPoints << std::endl;
}