#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm(void) : AForm("Undefined", 25,
															 5) {};

PresidentialPardonForm::PresidentialPardonForm(const std::string name) : AForm(
		name, 25, 5) {};

PresidentialPardonForm::PresidentialPardonForm(
		const PresidentialPardonForm &src)
		: AForm(src.getName(), 25, 5) {};

PresidentialPardonForm::~PresidentialPardonForm(void) {};

PresidentialPardonForm &
PresidentialPardonForm::operator=(const PresidentialPardonForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}


void PresidentialPardonForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);

	std::cout << this->getName() << " has been pardoned by Zaphod Beeblebrox."
			  << std::endl;
	return;
}
