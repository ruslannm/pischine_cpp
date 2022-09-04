#ifndef PHONEBOOK_H
#define PHONEBOOK_H
#define PHONEBOOK_SIZE 8

#include <iostream>
#include <iomanip>
#include "Contact.hpp"

class PhoneBook
{
public:
	PhoneBook();

	size_t getSize(void) const;

	void addContact(Contact);

	bool getContactByIndex(size_t, Contact *);

	void printContacts(void);

	static std::string truncate(std::string);

private:
	size_t _size;
	size_t _index;
	Contact _contacts[PHONEBOOK_SIZE];
};

#endif
