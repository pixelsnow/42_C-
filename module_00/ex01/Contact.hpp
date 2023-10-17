#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void displayDetails(void);
	void displayAsRow(void);

private:

	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	void displayAsCell(std::string); // try to use template maybe?

};

#endif