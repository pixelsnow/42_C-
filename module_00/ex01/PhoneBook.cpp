/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:32:00 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/19 16:32:33 by vvagapov         ###   ########.fr       */
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
	std::cout << "[instructions will be here]" << std::endl;
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
	for (int i=0; i<nextIndex; i++)
		contacts[i].displayAsRow();
	std::cout << "searching" << std::endl;

}
