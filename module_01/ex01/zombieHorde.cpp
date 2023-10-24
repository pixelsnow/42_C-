/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zombieHorde.cpp                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 17:34:23 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/24 19:27:04 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Zombie.hpp"

Zombie *zombieHorde(int N, std::string name)
{
	if (N < 0)
		return NULL;

	Zombie *arr = new Zombie[N];
	for (int i = 0; i < N; i++)
		arr[i].setName(name);

	return arr;
}