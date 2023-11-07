/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 20:57:28 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "FragTrap.hpp"

int main(void)
{
	FragTrap antti("Antti");

	antti.highFivesGuys();
	antti.attack("Jussi");
	antti.takeDamage(60);
	antti.takeDamage(60);
	antti.takeDamage(60);

	FragTrap antti2(antti);
	antti2.takeDamage(1);

	FragTrap noel("Noel");
	noel.takeDamage(60);
	noel = antti;
	noel.takeDamage(1);

	return 0;
}