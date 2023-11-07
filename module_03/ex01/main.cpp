/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 20:53:36 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap jussi("Jussi");

	jussi.guardGate();
	jussi.attack("Antti");
	jussi.takeDamage(60);
	jussi.takeDamage(60);
	jussi.takeDamage(60);

	ScavTrap jussi2(jussi);
	jussi2.takeDamage(1);

	ScavTrap noel("Noel");
	noel.takeDamage(60);
	noel = jussi;
	noel.takeDamage(1);

	return 0;
}