/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:04 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/04 20:44:00 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

/* CONSTRUCTORS */

ClapTrap::ClapTrap(std::string newName)
	: name(newName), hitPoints(10), energyPoints(10), attackDamage(0)
{
	std::cout << MAGENTA << "ClapTrap " << newName << " is created" << RESET << std::endl;
}

ClapTrap::ClapTrap(const ClapTrap &source)
	: name(source.name), hitPoints(source.hitPoints),
	  energyPoints(source.energyPoints), attackDamage(source.attackDamage)
{
	std::cout << MAGENTA << "ClapTrap " << this->name << " is created in the image of ClapTrap " << source.name << RESET << std::endl;
}

/* DESTRUCTOR */

ClapTrap::~ClapTrap(void)
{
	std::cout << MAGENTA << "ClapTrap " << this->name << " is destroyed" << RESET << std::endl;
}

/* OPERATORS */
ClapTrap &ClapTrap::operator=(const ClapTrap &source)
{
	std::cout << MAGENTA << "ClapTrap " << this->name << " is being turned into a clone of ClapTrap " << source.name << RESET << std::endl;
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
	std::cout << "     /  " << YELLOW << "+" << RESET << "  \\" << std::endl;
	std::cout << "     | ~~~ |" << std::endl;
	std::cout << "     |R.I.P|" << std::endl;
	std::cout << GREEN << "\\vV,," << WHITE << "|_____|" << GREEN << "V,v/," << RESET << std::endl
			  << std::endl;
}

void ClapTrap::printGhost(void) const
{
	std::cout << "Stop attacking the corpse of " << this->name << " pls" << std::endl
			  << std::flush;
	usleep(1000000);

	std::cout << std::endl
			  << std::flush;
	usleep(100000);
	std::cout << BLUE << " .-." << std::endl
			  << std::flush;
	usleep(100000);
	std::cout << "(o o) boo!" << std::endl
			  << std::flush;
	usleep(100000);
	std::cout << "| O \\" << std::endl
			  << std::flush;

	usleep(100000);
	std::cout << " \\   \\" << std::endl
			  << std::flush;

	usleep(100000);
	std::cout << "  `~~~'" << std::endl
			  << std::flush;
	usleep(100000);
	std::cout << std::endl
			  << std::flush;

	usleep(500000);
	std::cout << "That's right, asshole. You're being haunted now." << RESET << std::endl;
}

void ClapTrap::attack(const std::string &target)
{
	if (this->hitPoints <= 0 || this->energyPoints <= 0)
	{
		std::cout << RED << "ClapTrap " << this->name << " unsuccessfully tries to attack " << target << RESET << std::endl;
		return;
	}
	std::cout << "ClapTrap " << this->name << " attacks " << target << ",causing " << this->attackDamage << " points of damage" << std::endl;
	this->energyPoints--;
}

void ClapTrap::takeDamage(unsigned int amount)
{
	if (!this->hitPoints)
	{
		printGhost();
	}
	else if (amount > this->hitPoints)
	{
		this->hitPoints = 0;

		std::cout << YELLOW << "ClapTrap " << this->name << " dies after taking " << amount << " points of damage..." << RESET << std::endl
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
		std::cout << RED << "ClapTrap " << this->name << " unsuccessfully tries to repair itself :(" << RESET << std::endl;
		return;
	}

	hitPoints += amount;
	this->energyPoints--;

	std::cout << "ClapTrap " << this->name << " repairs itself by " << amount << " points, now " << this->name << "'s hit point count is " << this->hitPoints << std::endl;
}