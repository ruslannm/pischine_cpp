#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm(void) : AForm("Undefined", 72,
													   45) {};

RobotomyRequestForm::RobotomyRequestForm(const std::string name) : AForm(
		name, 72, 45) {};

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &src)
		: AForm(src.getName(), 72, 45) {};

RobotomyRequestForm::~RobotomyRequestForm(void) {};

RobotomyRequestForm &
RobotomyRequestForm::operator=(const RobotomyRequestForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}


void RobotomyRequestForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::cout << "Drrrrr" << std::endl;
	if (_success)
	{
		std::cout << this->getName() << " has been robotomized" << std::endl;
		_success = false;
	}
	else
	{
		std::cout << "the robotomy of " << this->getName() << " failed!"
				  << std::endl;
		_success = true;
	}
	return;
}

bool RobotomyRequestForm::_success = true;
