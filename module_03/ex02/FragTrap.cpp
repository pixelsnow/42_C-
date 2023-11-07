/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   FragTrap.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:06 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 16:31:15 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

FragTrap::FragTrap(std::string newName) : ScavTrap(newName)
{
	this->hitPoints = 100;
	this->energyPoints = 100;
	this->attackDamage = 30;
	std::cout << CYAN << "FragTrap " << newName << " is created" << RESET << std::endl;
}

FragTrap::~FragTrap(void)
{
	std::cout << CYAN << "FragTrap " << this->name << " is destroyed" << RESET << std::endl;
}

void FragTrap::highFivesGuys()
{
	std::cout << CYAN << "FragTrap " << this->name << " wants a high five " << RESET << "ヘ( ^o^)ノ＼(^_^ )" << std::endl;
}