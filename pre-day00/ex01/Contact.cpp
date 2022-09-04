#include "Contact.hpp"

Contact Contact::newContact(void)
{
	Contact contact;
	std::string str;
	std::string fields[5] = {"first name", "last name",
							 "nickname", "phone number", "darkest secret"};
	void (Contact::*func[5])(std::string) = {&Contact::setFirstname,
											 &Contact::setLastname,
											 &Contact::setNickname,
											 &Contact::setPhoneNumber,
											 &Contact::setDarkestSecret};
	for (size_t i = 0; i != 5; ++i)
	{
		std::cout << "Input " << fields[i] << ": ";
		std::getline(std::cin, str);
		(&contact->*func[i])(str);
	}
	return contact;
}

Contact::Contact() : _firstname(""),
					 _lastname(""),
					 _nickname(""),
					 _phoneNumber(""),
					 _darkestSecret("") {};

void Contact::print()
{
	std::string fields[5] = {"first name", "last name",
							 "nickname", "phone number",
							 "darkest secret"};
	std::string(Contact::*
	func[5])(void) const = {
		&Contact::getFirstname,
				&Contact::getLastname,
				&Contact::getNickname,
				&Contact::getPhoneNumber,
				&Contact::getDarkestSecret
	};
	for (size_t i = 0; i != 5; ++i)
	{
		std::cout << std::setw(15) << std::left << fields[i];
		std::cout << ":" << (this->*func[i])() << std::endl;
	}
};

void Contact::setFirstname(std::string str)
{
	_firstname = str;
};

void Contact::setLastname(std::string str)
{
	_lastname = str;
};

void Contact::setNickname(std::string str)
{
	_nickname = str;
};

void Contact::setPhoneNumber(std::string str)
{
	_phoneNumber = str;
};

void Contact::setDarkestSecret(std::string str)
{
	_darkestSecret = str;
};

std::string Contact::getFirstname(void) const { return _firstname; }

std::string Contact::getLastname(void) const { return _lastname; }

std::string Contact::getNickname(void) const { return _nickname; }

std::string Contact::getPhoneNumber(void) const { return _phoneNumber; }

std::string Contact::getDarkestSecret(void) const { return _darkestSecret; }
