#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	std::cout << "Test without exception:" << std::endl;
	try
	{
		Form formA("A", 1, 1);
		Bureaucrat john = Bureaucrat("John", 1);
		std::cout << formA << std::endl;
		john.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	std::cout << "Tests with exceptions:" << std::endl;

	try
	{
		Form formA("A", 1, 0);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form formA("A", 1, 151);
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	try
	{
		Form formA("A", 1, 1);
		Bureaucrat john = Bureaucrat("John", 2);
		std::cout << formA << std::endl;
		std::cout << john << std::endl;
		john.signForm(formA);
		std::cout << formA << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}
