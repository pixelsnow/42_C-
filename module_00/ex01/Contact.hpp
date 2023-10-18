#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

public:

	Contact(int index,
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string secret);
	~Contact(void);
	void displayDetails(void) const;
	void displayAsRow(void) const;

private:

	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	void displayAsCell(std::string) const; // try to use template maybe?

};

#endif