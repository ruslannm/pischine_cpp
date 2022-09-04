#include "PhoneBook.hpp"

std::string PhoneBook::truncate(std::string str)
{
	if (str.length() > 10)
		return (str.substr(0, 9) + ".");
	else
		return (str);
};

PhoneBook::PhoneBook() : _size(0), _index(0) {};

size_t PhoneBook::getSize(void) const
{
	return _size;
};

void PhoneBook::addContact(Contact contact)
{
	if (!(contact.getFirstname().empty() ||
		  contact.getLastname().empty() ||
		  contact.getNickname().empty() ||
		  contact.getPhoneNumber().empty() ||
		  contact.getDarkestSecret().empty()))
	{
		this->_contacts[_index] = contact;
		if (_size == PHONEBOOK_SIZE)
		{
			if (_index == PHONEBOOK_SIZE - 1)
			{
				_index = 0;
			}
			else
			{
				++_index;
			}
		}
		else
		{
			_size = ++_index;
			if (_index == PHONEBOOK_SIZE)
			{
				_index = 0;
			}
		}
	}
};

bool PhoneBook::getContactByIndex(size_t index, Contact *contact)
{
	if (0 <= index && index < _size)
	{
		*contact = _contacts[index];
		return true;
	}
	return false;
};

void PhoneBook::printContacts()
{
	if (_size == 0)
	{
		std::cout << "No contacts." << std::endl << std::endl;
		return;
	}
	else
	{
		std::cout << "|" << std::setw(10) << "index";
		std::cout << "|" << std::setw(10) << "first name";
		std::cout << "|" << std::setw(10) << "last name";
		std::cout << "|" << std::setw(10) << "nickname" << "|" << std::endl;
		for (size_t i = 0; i < _size; ++i)
		{
			std::cout << "|" << std::setw(10) << i;
			std::cout << "|" << std::setw(10)
					  << truncate(_contacts[i].getFirstname());
			std::cout << "|" << std::setw(10)
					  << truncate(_contacts[i].getLastname());
			std::cout << "|" << std::setw(10)
					  << truncate(_contacts[i].getNickname());
			std::cout << "|" << std::endl;
		}
	}
}
