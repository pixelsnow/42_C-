/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ClapTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:45:02 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 21:03:57 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLAPTRAP_HPP
#define CLAPTRAP_HPP

#include "colours.hpp"
#include <iostream>
#include <unistd.h>

class ClapTrap
{
private:
	std::string name;
	unsigned int hitPoints;
	unsigned int energyPoints;
	unsigned int attackDamage;

	void printTombstone(void) const;
	void printGhost(void) const;

public:
	ClapTrap(std::string newName);
	ClapTrap(const ClapTrap &source);
	~ClapTrap(void);

	ClapTrap &operator=(const ClapTrap &source);

	void attack(const std::string &target);
	void takeDamage(unsigned int amount);
	void beRepaired(unsigned int amount);
};

#endif