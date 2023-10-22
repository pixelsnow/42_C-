/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:32:00 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/22 21:02:56 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PhoneBook.hpp"

PhoneBook::PhoneBook(void) : nextIndex(0), size(0)
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

void PhoneBook::displayContactIndexCell(int index) const
{
	std::cout << std::setw (10) << index << "|";
}

void PhoneBook::displayContactTextCell(std::string str) const
{
	if (str.length() > 10)
		std::cout << str.substr(0, 9) << ".|";
	else
		std::cout << std::setw (10) << str << "|";
}

void PhoneBook::displayContactDetails(int index) const
{
	std::cout << "first name: " << contacts[index].getFirstName() << std::endl;
	std::cout << "last name: " << contacts[index].getLastName() << std::endl;
	std::cout << "nickname: " << contacts[index].getNickname() << std::endl;
	std::cout << "phone number: " << contacts[index].getPhoneNumber() << std::endl;
	std::cout << "darkest secret: " << contacts[index].getSecret() << std::endl;
}

void PhoneBook::displayContactAsRow(int index) const
{
	std::cout << "    |";
	displayContactIndexCell(index);
	displayContactTextCell(contacts[index].getFirstName());
	displayContactTextCell(contacts[index].getLastName());
	displayContactTextCell(contacts[index].getNickname());
	std::cout << std::endl;
}

void PhoneBook::printInstructions(void)
{
	std::cout << "   ___________________________________________" << std::endl;
	std::cout << " / \\                                          \\" << std::endl;
	std::cout << "|   |  Here are the only available commands:  |" << std::endl;
	std::cout << " \\_ |                                         |" << std::endl;
	std::cout << "    |    ‣ ADD - Adds a new contact           |" << std::endl;
	std::cout << "    |    ‣ SEARCH - Displays saved contacts   |" << std::endl;
	std::cout << "    |    ‣ EXIT - The program quits and       |" << std::endl;
	std::cout << "    |        your contacts are lost FOREVER!  |" << std::endl;
	std::cout << "    |   ______________________________________|___" << std::endl;
	std::cout << "    |  /                                         /" << std::endl;
	std::cout << "    \\_/_________________________________________/" << std::endl;
	std::cout << std::endl;
}

std::string getValueInput(std::string prompt)
{
	std::string inputValue;

	std::cout << "‣ " << prompt << ":" << std::endl;
	while (std::getline(std::cin, inputValue))
	{
		if (!inputValue.length())
			std::cout << "✖ " << prompt << " can't be empty, try again" << std::endl;
		else
			break;
	}
	return (inputValue);
}

void PhoneBook::add(void)
{
	Contact newContact;
	std::string inputValue;

	newContact.setFirstName(getValueInput("first name"));
	if (std::cin.eof())
		return;
	newContact.setLastName(getValueInput("last name"));
	if (std::cin.eof())
		return;
	newContact.setNickname(getValueInput("nickname"));
	if (std::cin.eof())
		return;
	newContact.setPhoneNumber(getValueInput("phone number"));
	if (std::cin.eof())
		return;
	newContact.setSecret(getValueInput("darkest secret"));
	if (std::cin.eof())
		return;

	contacts[nextIndex].copyContactInfo(newContact);
	std::cout << "✴ " << newContact.getFirstName() << " has been added to your awesomest phonebook ✴" << std::endl;
	nextIndex++;
	nextIndex %= 8;
	if (size < 8)
		size++;
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
		displayContactAsRow(i);
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
	while (std::getline(std::cin, indexToShow)) // also check if number and if in range
	{
		if (isValidIndex(indexToShow))
		{
			displayContactDetails(std::stoi(indexToShow));
			break;
		}
		else
		{
			std::cout << "Not a valid index, try again" << std::endl;
		}
	}
}
