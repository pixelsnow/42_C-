#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

public:

	Contact(void);
	~Contact(void);
	void setContactInfo(int index,
		std::string firstName,
		std::string lastName,
		std::string nickname,
		std::string phoneNumber,
		std::string secret);
	void displayDetails(void) const;
	void displayAsRow(void) const;

private:

	int index;
	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

	void displayIndexCell() const;
	void displayTextCell(std::string str) const; // try to use template maybe?

};

#endif