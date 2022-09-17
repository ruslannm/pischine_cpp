#include "Bureaucrat.hpp"
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "RobotomyRequestForm.hpp"
#include "PresidentialPardonForm.hpp"

int main(void)
{
	std::cout << "Test canonical methods:" << std::endl;
	{
		AForm *form0 = new ShrubberyCreationForm();
		std::cout << form0 << " " << *form0 << std::endl;
		AForm *form1 = new ShrubberyCreationForm("28A");
		std::cout << form1 << " " << *form1 << std::endl;
		AForm *form2 = new ShrubberyCreationForm(
				*((const ShrubberyCreationForm *) form1));
		std::cout << form2 << " " << *form2 << std::endl;
		*form0 = *form1;
		std::cout << form0 << " " << *form0 << std::endl;
		delete form0;
		delete form1;
		delete form2;
	}
	std::cout << std::endl;

	std::cout << "Test without exception:" << std::endl;
	try
	{
		Bureaucrat john("John", 137);
		AForm *form = new ShrubberyCreationForm("28A");
		std::cout << *form << std::endl;
		john.signForm(*form);
		std::cout << *form << std::endl;
		form->execute(john);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		Bureaucrat john("John", 137);
		AForm *form = new ShrubberyCreationForm("28A");
		std::cout << *form << std::endl;
		john.signForm(*form);
		std::cout << *form << std::endl;
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat john("John", 45);
		AForm *form = new RobotomyRequestForm("28B");
		std::cout << *form << std::endl;
		john.signForm(*form);
		std::cout << *form << std::endl;
		john.executeForm(*form);
		john.executeForm(*form);
		john.executeForm(*form);
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat john("John", 5);
		AForm *form = new PresidentialPardonForm("28C");
		std::cout << *form << std::endl;
		john.signForm(*form);
		std::cout << *form << std::endl;
		john.executeForm(*form);
		delete form;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Test with exceptions:" << std::endl;
	std::cout << std::endl << "Test 1" << std::endl;
	AForm *forms[3];
	forms[0] = new ShrubberyCreationForm("28A");
	forms[1] = new RobotomyRequestForm("28B");
	forms[2] = new PresidentialPardonForm("28C");
	try
	{
		Bureaucrat john("John", 145);
		for (size_t i = 0; i != 3; ++i)
		{
			std::cout << *forms[i] << std::endl;
			john.signForm(*forms[i]);
			john.executeForm(*forms[i]);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (size_t i = 0; i != 3; ++i)
	{
		delete forms[i];
	}
	std::cout << std::endl;
	std::cout << std::endl << "Test 2" << std::endl;
	forms[0] = new ShrubberyCreationForm("28A");
	forms[1] = new RobotomyRequestForm("28B");
	forms[2] = new PresidentialPardonForm("28C");
	try
	{
		Bureaucrat john("John", 72);
		for (size_t i = 0; i != 3; ++i)
		{
			std::cout << *forms[i] << std::endl;
			john.signForm(*forms[i]);
			john.executeForm(*forms[i]);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (size_t i = 0; i != 3; ++i)
	{
		delete forms[i];
	}
	std::cout << std::endl;
	std::cout << std::endl << "Test 3" << std::endl;
	forms[0] = new ShrubberyCreationForm("28A");
	forms[1] = new RobotomyRequestForm("28B");
	forms[2] = new PresidentialPardonForm("28C");
	try
	{
		Bureaucrat john("John", 25);
		for (size_t i = 0; i != 3; ++i)
		{
			std::cout << *forms[i] << std::endl;
			john.signForm(*forms[i]);
			john.executeForm(*forms[i]);
		}
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	for (size_t i = 0; i != 3; ++i)
	{
		delete forms[i];
	}
	return 0;
}
