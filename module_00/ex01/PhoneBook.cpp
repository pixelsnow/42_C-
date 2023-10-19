/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:32:00 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/19 19:37:34 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nextIndex(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	return;
}

void PhoneBook::printInstructions(void)
{
	std::cout << "   ___________________________________________" << std::endl;
	std::cout << " / \\                                          \\" << std::endl;
	std::cout << "|   |  WELCOME TO YOUR CRAPPY 80S PHONEBOOK!  |" << std::endl;
	std::cout << " \\_ |                                         |" << std::endl;
	std::cout << "    |  Here's the little that it can do:      |" << std::endl;
	std::cout << "    |                                         |" << std::endl;
	std::cout << "    |    ‣ ADD - Adds a new contact           |" << std::endl;
	std::cout << "    |    ‣ SEARCH - Displays saved contacts   |" << std::endl;
	std::cout << "    |    ‣ EXIT - The program quits and       |" << std::endl;
	std::cout << "    |        your contacts are lost FOREVER!  |" << std::endl;
	std::cout << "    |   ______________________________________|___" << std::endl;
	std::cout << "    |  /                                         /" << std::endl;
	std::cout << "    \\_/_________________________________________/" << std::endl;
	std::cout << std::endl;
}

void PhoneBook::add(void)
{
	std::string	newFirstName;

	std::cout << "first name:" << std::endl;
	while (newFirstName.length() == 0)
		std::cin >> newFirstName;
	contacts[nextIndex].setContactInfo(nextIndex, newFirstName, "lastname", "nick", "phone", "secret");
	nextIndex++;
	nextIndex %= 8;
	std::cout << "adding" << std::endl;
}

void PhoneBook::search(void)
{
	std::string	indexToShow;

	// handle empty case
	for (int i=0; i<nextIndex; i++)
		contacts[i].displayAsRow();
	std::cout << "enter index" << std::endl;
	while (!indexToShow.length()) // also check if number and if in range
		std::cin >> indexToShow;
	contacts[std::stoi(indexToShow)].displayDetails();
}
