#include "Bureaucrat.hpp"

int main(void)
{
	std::cout << "Test without exception:" << std::endl;
	try
	{
		Bureaucrat john = Bureaucrat("John", 1);
		std::cout << john << std::endl;
		john.decreaseGrade();
		std::cout << john << std::endl;
		john.decreaseGrade();
		std::cout << john << std::endl;
		john.increaseGrade();
		std::cout << john << std::endl;
		john.increaseGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	std::cout << "Tests with exceptions:" << std::endl;
	try
	{
		Bureaucrat john = Bureaucrat("John");
		std::cout << john << std::endl;
		john.decreaseGrade();
		std::cout << john << std::endl;
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}
	std::cout << std::endl;

	try
	{
		Bureaucrat john = Bureaucrat("John");
		std::cout << john << std::endl;
		for(int i = 0; i != 149; ++i)
		{
			john.increaseGrade();
		}
		std::cout << john << std::endl;
		john.increaseGrade();
	}
	catch (std::exception &e)
	{
		std::cout << e.what() << std::endl;
	}

	return 0;
}

