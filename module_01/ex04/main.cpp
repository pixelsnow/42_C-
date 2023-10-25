/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 13:57:35 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/25 19:49:04 by vvagapov         ###   ########.fr       */
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
	std::cout << "Usage: <filename> <old_value> <new_value>" << std::endl;
}

void printError(int code)
{
	switch (code)
	{
	case (FAULTY_FILENAME_ERROR):
		printErrorMessage("Filename can't be empty");
		break;
	case (IN_FILE_OPEN_ERROR):
		printErrorMessage("Input file: not found or insufficient permissions");
		break;
	case (OUT_FILE_OPEN_ERROR):
		printErrorMessage("Output file: insufficient permissions");
		break;
	case (FAULTY_S1_ERROR):
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

	returnRes = replacer.run(av[1], av[2], av[3]);
	printError(returnRes);
	return returnRes;
}