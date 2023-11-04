/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/04 21:08:13 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ScavTrap.hpp"

int main(void)
{
	ScavTrap jussi("Jussi");

	/* ScavTrap pentti("Pentti");

	pentti = jussi; */
	jussi.takeDamage(1000);

	return 0;
}