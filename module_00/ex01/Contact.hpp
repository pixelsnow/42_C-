#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <iostream>

class Contact {

public:

	Contact(void);
	/* Contact(Contact template); */
	~Contact(void);
	
	void copyContactInfo(Contact source);
	void setFirstName(std::string newFirstName);
	void setLastName(std::string newLastName);
	void setNickname(std::string newNickname);
	void setPhoneNumber(std::string newPhoneNumber);
	void setSecret(std::string newSecret);
	std::string getFirstName(void) const;
	std::string getLastName(void) const;
	std::string getNickname(void) const;
	std::string getPhoneNumber(void) const;
	std::string getSecret(void) const;

private:

	std::string firstName;
	std::string lastName;
	std::string nickname;
	std::string phoneNumber;
	std::string secret;

};

#endif