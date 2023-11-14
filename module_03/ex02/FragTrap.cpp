/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:06 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/14 13:16:21 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string newName) : ClapTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << GREEN << "FragTrap " << newName << " is created" << RESET << std::endl;
}

FragTrap::FragTrap(const FragTrap &source) : ClapTrap(source)
{
	std::cout << MAGENTA << "FragTrap " << this->name << " is created in the image of FragTrap " << source.name << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << GREEN << "FragTrap " << this->name << " is destroyed" << RESET << std::endl;
}

FragTrap &FragTrap::operator=(const FragTrap &source)
{
	std::cout << MAGENTA << "FragTrap " << this->name << " is being turned into a clone of FragTrap " << source.name << RESET << std::endl;
	this->name = source.name;
	this->hitPoints = source.hitPoints;
	this->energyPoints = source.energyPoints;
	this->attackDamage = source.attackDamage;
	return *this;
}

void FragTrap::highFivesGuys() const
{
	std::cout << GREEN << "FragTrap " << this->name << " wants a high five " << RESET << "ヘ( ^o^)ノ＼(^_^ )" << std::endl;
}