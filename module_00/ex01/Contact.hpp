/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Contact.hpp                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.hive.fi>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:13:01 by vvagapov          #+#    #+#             */
/*   Updated: 2023/10/23 15:13:03 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONTACT_HPP
# define CONTACT_HPP

# include <string>

class Contact {

public:

	Contact(void);
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