/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:35 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 14:01:15 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#define ERROR 1
#define SUCCESS 0

void printArgNumError(void)
{
	std::cout << "Usage: <filename> <s1> <s2>" << std::endl;
}

int main(int ac, char **av)
{
	if (ac != 3)
	{
		printArgNumError();
		return (1);
	}
	(void)av;
	return 0;
}