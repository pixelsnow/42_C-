#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void add(void);
	void search(void);
	void printInstructions(void);

private:

	Contact contacts[8];
	int nextIndex;

};

#endif