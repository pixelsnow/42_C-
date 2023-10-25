/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   HumanB.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:39:40 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 13:55:04 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HUMANB_HPP
#define HUMANB_HPP

#include <iostream>
#include "Weapon.hpp"

class HumanB
{
private:
	Weapon *weapon;
	std::string name;

public:
	HumanB(std::string newName);
	~HumanB(void);

	void attack(void) const;
	void setWeapon(Weapon &newWeapon);
};

#endif