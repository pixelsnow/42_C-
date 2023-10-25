/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Weapon.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 20:39:47 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 13:52:19 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Weapon.hpp"

Weapon::Weapon(std::string newType)
{
	type = newType;
}

Weapon::~Weapon() {}

const std::string &Weapon::getType()
{
	return type;
}

void Weapon::setType(std::string newType)
{
	type = newType;
}