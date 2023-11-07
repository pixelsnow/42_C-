/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/04 16:37:26 by vvagapov          #+#    #+#             */
/*   Updated: 2023/11/07 17:07:45 by vvagapov         ###   ########.fr       */
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

	return 0;
}