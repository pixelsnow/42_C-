/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 16:53:38 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/24 19:29:04 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

#define NUM 5

Zombie *zombieHorde(int N, std::string name);

int main(void)
{
	Zombie *horde = zombieHorde(NUM, "Heap");
	for (int i = 0; i < NUM; i++)
		horde[i].announce();
	delete[] horde;
	return 0;
}