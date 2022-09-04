#ifndef CONTACT_HPP
#define CONTACT_HPP

#include <iostream>
#include <iomanip>

class Contact
{
public:
	static Contact newContact(void);

	Contact();

	void print();

	void setFirstname(std::string);

	void setLastname(std::string);

	void setNickname(std::string);

	void setPhoneNumber(std::string);

	void setDarkestSecret(std::string);

	std::string getFirstname(void) const;

	std::string getLastname(void) const;

	std::string getNickname(void) const;

	std::string getPhoneNumber(void) const;

	std::string getDarkestSecret(void) const;

private:
	std::string _firstname;
	std::string _lastname;
	std::string _nickname;
	std::string _phoneNumber;
	std::string _darkestSecret;
};

#endif
