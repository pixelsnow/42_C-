/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:32:00 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/20 17:54:49 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"
#include <unistd.h>
#include <iomanip>

PhoneBook::PhoneBook(void) : nextIndex(0)
{
	return;
}

PhoneBook::~PhoneBook(void)
{
	std::string message = "Deleting your loved ones' contacts ";
	std::string accentWord = "FOREVER";
	std::string progress = " . . . . .";

	for (int i = 0; i < message.length(); i++)
	{
		std::cout << message[i] << std::flush;
		usleep(20000);
	}
	for (int i = 0; i < accentWord.length(); i++)
	{
		std::cout << accentWord[i] << std::flush;
		usleep(100000);
	}
	for (int i = 0; i < progress.length(); i++)
	{
		std::cout << progress[i] << std::flush;
		if (i % 2)
			usleep(200000);
	}
	std::cout << std::endl;
	return;
}

void PhoneBook::printInstructions(void)
{
	std::cout << "   ___________________________________________" << std::endl;
	std::cout << " / \\                                          \\" << std::endl;
	std::cout << "|   |  WELCOME TO YOUR CRAPPY 80S PHONEBOOK!  |" << std::endl;
//	std::cout << "|   |                                         |" << std::endl;
//	std::cout << " \\_ |  WELCOME TO YOUR CRAPPY 80S PHONEBOOK!  |" << std::endl;
	std::cout << " \\_ |                                         |" << std::endl;
//	std::cout << "    |                                         |" << std::endl;
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

	std::cout << "‣ first name:" << std::endl;
	while (newFirstName.length() == 0)
		std::getline(std::cin, newFirstName);
	contacts[nextIndex].setContactInfo(nextIndex, newFirstName, "lastname", "nick", "phone", "secret");
	nextIndex++;
	nextIndex %= 8;
	std::cout << "✴ " << newFirstName << " has been added to your awesomest phonebook ✴" << std::endl;
}

bool PhoneBook::isValidIndex(std::string searchIndex) const
{
	return (searchIndex.length() == 1
		&& searchIndex[0] >= '0'
		&& searchIndex[0] < '0' + nextIndex);
}

void PhoneBook::displayTableHeaders(void) const
{
	std::cout << "    |";
	std::cout << std::setw (10) << "index" << "|";
	std::cout << std::setw (10) << "first name" << "|";
	std::cout << std::setw (10) << "last name" << "|";
	std::cout << std::setw (10) << "nickname" << "|";
	std::cout << std::endl;
}

void PhoneBook::printPhoneBook(void)
{
	std::cout << "   _____________________________________________" << std::endl;
	std::cout << " / \\                                            \\" << std::endl;
	std::cout << "|   |   WELCOME TO YOUR CRAPPY 80S PHONEBOOK!   |" << std::endl;
		std::cout << " \\_ |                                           |" << std::endl;
	displayTableHeaders();
	std::cout << "    |-------------------------------------------|" << std::endl;
	for (int i=0; i<nextIndex; i++)
		contacts[i].displayAsRow();
	std::cout << "    |   ________________________________________|___" << std::endl;
	std::cout << "    |  /                                           /" << std::endl;
	std::cout << "    \\_/___________________________________________/" << std::endl;
}

void PhoneBook::search(void)
{
	std::string	indexToShow;

	if (nextIndex == 0)
	{
		std::cout << "Your awesomest phonebook is empty... Type ADD to fix it" << std::endl;
		return;
	}
	// handle empty case
	printPhoneBook();
	std::cout << "‣ index" << std::endl;
	while (1) // also check if number and if in range
	{
		std::getline(std::cin, indexToShow);
		if (isValidIndex(indexToShow))
		{
			contacts[std::stoi(indexToShow)].displayDetails();
			break;
		}
		else
		{
			std::cout << "Not a valid index, try again" << std::endl;
		}
	}
}
