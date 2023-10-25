/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:35 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 18:27:45 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <iostream>
#include "Replacer.hpp"

void printErrorMessage(std::string message)
{
	std::cout << "ERROR: " << message << std::endl;
}

void printUsageError()
{
	std::cout << "Usage: <filename> <old value> <new value>" << std::endl;
}

void printError(int code, Replacer replacer)
{
	switch (code)
	{
	case (IN_FILE_OPEN_ERROR):
		printErrorMessage("File not found");
		break;
	case (EMPTY_S1_ERROR):
		printErrorMessage("String to replace can't be empty");
		break;
	}
}

int main(int ac, char **av)
{
	Replacer replacer;
	int returnRes;

	if (ac != 4)
	{
		printUsageError();
		return (ARG_NUM_ERROR);
	}

	returnRes = replacer.go(av[1], av[2], av[3]);
	printError(returnRes, replacer);
	return returnRes;
}