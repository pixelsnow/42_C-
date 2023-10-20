#include "Contact.hpp"
#include <iomanip>

/* Contact::Contact(void)
			: index(0),
				firstName(firstName),
				lastName(lastNameInit),
				nickname(nicknameInit),
				phoneNumber(phoneNumberInit),
				secret(secretInit)
{
	return;
} */

Contact::Contact(void)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::setContactInfo(int newIndex,
		std::string newFirstName,
		std::string newLastName,
		std::string newNickname,
		std::string newPhoneNumber,
		std::string newSecret)
{
	index = newIndex;
	firstName = newFirstName;
	lastName = newLastName;
	nickname = newNickname;
	phoneNumber = newPhoneNumber;
	secret = newSecret;
}

void Contact::displayIndexCell(void) const
{
	std::cout << std::setw (10) << index << "|";
}

void Contact::displayTextCell(std::string str) const
{
	std::cout << std::setw (10) << str << "|";
}

void Contact::displayDetails(void) const
{
	std::cout << "first name: " << firstName << std::endl;
	std::cout << "last name: " << lastName << std::endl;
	std::cout << "nickname: " << nickname << std::endl;
	std::cout << "phone number: " << phoneNumber << std::endl;
	std::cout << "darkest secret: " << secret << std::endl;
}

void Contact::displayAsRow(void) const
{
	std::cout << "    |";
	displayIndexCell();
	displayTextCell(firstName);
	displayTextCell(lastName);
	displayTextCell(nickname);
	std::cout << std::endl;
}
