/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 19:58:59 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 22:50:52 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Harl.hpp"

int usageError(void)
{
	std::cout << "Usage: ./harlFilter LEVEL" << std::endl;
	std::cout << "Levels: "
			  << "DEBUG"
			  << ", "
			  << "INFO"
			  << ", "
			  << "WARNING"
			  << ", "
			  << "ERROR" << std::endl;
	return 1;
}

int getLevelNum(std::string levelStr)
{
	std::string levelNames[] = {"DEBUG",
								"INFO",
								"WARNING",
								"ERROR"};
	for (int i = 0; i < 4; i++)
		if (levelStr == levelNames[i])
			return (i);
	return (-1);
}

void complainWithLevel(Harl &harl, std::string level)
{
	std::cout << "[" << level << "]" << std::endl;
	harl.complain(level);
	std::cout << std::endl;
}

void complainGeneric(void)
{
	std::cout << "[ Probably complaining about insignificant problems ]" << std::endl;
}

int main(int ac, char **av)
{
	Harl harl;
	int level;

	if (ac != 2)
		return (usageError());

	level = getLevelNum(av[1]);

	switch (level)
	{
	case 0:
		complainWithLevel(harl, "DEBUG");
	case 1:
		complainWithLevel(harl, "INFO");
	case 2:
		complainWithLevel(harl, "WARNING");
	case 3:
		complainWithLevel(harl, "ERROR");
		break;
	default:
		complainGeneric();
	}

	return 0;
}