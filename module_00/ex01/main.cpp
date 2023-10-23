/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:12:30 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/23 15:12:33 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (std::getline(std::cin, command))
	{
		std::transform(command.begin(), command.end(), command.begin(),
				::tolower);
		if (command == "exit")
			break;
		else if (command == "add")
			phonebook.add();
		else if (command == "search")
			phonebook.search();
		else
			phonebook.printInstructions();
	}
	return 0;
}
