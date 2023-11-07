/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 17:07:32 by vvagapov         ###   ########.fr       */
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

	return 0;
}