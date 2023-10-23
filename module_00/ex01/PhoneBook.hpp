#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# define SIZE 3
# include "Contact.hpp"
# include <iomanip>
# include <iostream>
# include <unistd.h>

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void);
	void printInstructions(void);

private:

	Contact contacts[SIZE];
	int nextIndex;
	int size;

	bool isValidIndex(std::string searchIndex) const;
	void printPhoneBook(void);
	void displayTableHeaders(void) const;
	void displayContactDetails(int index) const;
	void displayContactAsRow(int index) const;
	void displayContactIndexCell(int index) const;
	void displayContactTextCell(std::string str) const;

};

#endif