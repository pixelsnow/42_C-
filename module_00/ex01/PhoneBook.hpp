#ifndef PHONEBOOK_HPP
# define PHONEBOOK_HPP

# include "Contact.hpp"

class PhoneBook {

public:

	PhoneBook(void);
	~PhoneBook(void);
	void run(void);

private:

	Contact contacts[8];
	void printInstructions(void);

};

#endif