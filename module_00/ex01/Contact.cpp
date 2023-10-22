#include "Contact.hpp"

Contact::Contact(void) {}

Contact::~Contact(void) {}

void Contact::copyContactInfo(Contact source)
{
	firstName = source.getFirstName();
	lastName = source.getLastName();
	nickname = source.getNickname();
	phoneNumber = source.getPhoneNumber();
	secret = source.getSecret();
}

void Contact::setFirstName(std::string newFirstName)
{
	firstName = newFirstName;
}

void Contact::setLastName(std::string newLastName)
{
	lastName = newLastName;
}

void Contact::setNickname(std::string newNickname)
{
	nickname = newNickname;
}

void Contact::setPhoneNumber(std::string newPhoneNumber)
{
	phoneNumber = newPhoneNumber;
}

void Contact::setSecret(std::string newSecret)
{
	secret = newSecret;
}

std::string Contact::getFirstName(void) const
{
	return firstName;
}

std::string Contact::getLastName(void) const
{
	return lastName;
}

std::string Contact::getNickname(void) const
{
	return nickname;
}

std::string Contact::getPhoneNumber(void) const
{
	return phoneNumber;
}

std::string Contact::getSecret(void) const
{
	return secret;
}
