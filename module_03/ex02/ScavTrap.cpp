/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:44:57 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 16:24:10 by vvagapov         ###   ########.fr       */
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

ScavTrap::~ScavTrap(void)
{
	std::cout << CYAN << "ScavTrap " << this->name << " is destroyed" << RESET << std::endl;
}

void ScavTrap::guardGate(void)
{
	std::cout << CYAN << "ScavTrap " << this->name << " is now in Gate keeper mode" << RESET << std::endl;
}