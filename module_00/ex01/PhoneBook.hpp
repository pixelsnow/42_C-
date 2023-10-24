/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:11:51 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/23 15:21:40 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SIZE 8

# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <unistd.h>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void) const;
	void printInstructions(void) const;

private:

	Contact contacts[SIZE];
	int nextIndex;
	int size;
	
	bool isValidIndex(std::string searchIndex) const;
	std::string getValueInput(std::string prompt) const;
	void printPhoneBook(void) const;
	void displayTableHeaders(void) const;
	void displayContactDetails(int index) const;
	void displayContactAsRow(int index) const;
	void displayContactIndexCell(int index) const;
	void displayContactTextCell(std::string str) const;

};

#endif