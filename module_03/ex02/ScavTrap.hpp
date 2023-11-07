/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ScavTrap.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:44:53 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 16:23:43 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SCAVTRAP_HPP
#define SCAVTRAP_HPP

#include "ClapTrap.hpp"
#include "colours.hpp"
#include <iostream>

class ScavTrap : public ClapTrap
{
private:
public:
	ScavTrap(std::string newName);
	~ScavTrap(void);

	void guardGate(void);
};

#endif