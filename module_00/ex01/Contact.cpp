#include "Contact.hpp"

Contact::Contact(int indexInit,
		std::string firstNameInit,
		std::string lastNameInit,
		std::string nicknameInit,
		std::string phoneNumberInit,
		std::string secretInit)
			: index(indexInit),
				firstName(firstName),
				lastName(lastNameInit),
				nickname(nicknameInit),
				phoneNumber(phoneNumberInit),
				secret(secretInit)
{
	return;
}

Contact::~Contact(void)
{
	return;
}

void Contact::displayAsCell(std::string) const
{
}

void Contact::displayDetails(void) const
{
}

void Contact::displayAsRow(void) const
{
}