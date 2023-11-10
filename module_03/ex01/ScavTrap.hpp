/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:44:53 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 21:15:30 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
public:
	ScavTrap(std::string newName);
	ScavTrap(const ScavTrap &source);
	~ScavTrap(void);

	ScavTrap &operator=(const ScavTrap &source);

	void attack(const std::string &target);
	void guardGate(void) const;
};

#endif