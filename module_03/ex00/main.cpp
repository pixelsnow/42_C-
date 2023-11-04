/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/04 20:13:34 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ClapTrap.hpp"

int main(void)
{
	ClapTrap mike("Ville");

	mike.attack("Perttu");

	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.takeDamage(2);
	mike.beRepaired(2);
	mike.beRepaired(2);
	mike.beRepaired(2);
	mike.takeDamage(20);
	mike.beRepaired(2);
	return 0;
}