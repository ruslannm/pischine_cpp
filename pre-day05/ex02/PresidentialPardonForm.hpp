#ifndef PRESIDENTIALPARDONFORM_HPP
#define PRESIDENTIALPARDONFORM_HPP

# include <iostream>
# include "AForm.hpp"

class PresidentialPardonForm : public AForm
{
public:
	PresidentialPardonForm(void);

	PresidentialPardonForm(const std::string);

	PresidentialPardonForm(const PresidentialPardonForm &);

	~PresidentialPardonForm(void);

	PresidentialPardonForm &operator=(const PresidentialPardonForm &);

	void execute(Bureaucrat const &executor) const;
};

#endif
