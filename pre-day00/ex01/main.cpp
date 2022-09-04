#include <iostream>
#include "Contact.hpp"
#include "PhoneBook.hpp"

static bool getIndex(size_t *index)
{
	size_t tmp;
	std::string str;
	std::cout << "Get contact by index, enter index:";
	std::cin >> tmp;
	if (std::cin.fail())
	{
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return false;
	}
	*index = tmp;
	return true;
}

void phonebook()
{
	std::string command;
	PhoneBook phoneBook;
	while (true)
	{
		std::cout << "Enter command (ADD, SEARCH, EXIT):";
		std::cin >> command;
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		if (command.compare("EXIT") == 0)
		{
			std::cout << "Good bye" << std::endl;
			return;
		}
		if (command.compare("ADD") == 0)
		{
			phoneBook.addContact(Contact::newContact());
		}
		else
		{
			if (command.compare("SEARCH") == 0)
			{
				phoneBook.printContacts();
				if (phoneBook.getSize())
				{
					size_t index;
					Contact contact;
					if (getIndex(&index) &&
						phoneBook.getContactByIndex(index, &contact))
					{
						contact.print();
					}
					else
					{
						std::cout << "Index out of bound" << std::endl;;
					}
				}
			}
		}

	}
}


int main()
{
	phonebook();
	return 0;
}