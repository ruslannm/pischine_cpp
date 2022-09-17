#ifndef ROBOTOMYREQUESTFORM_HPP
#define ROBOTOMYREQUESTFORM_HPP

# include <iostream>
# include "AForm.hpp"

class RobotomyRequestForm : public AForm
{
public:
	RobotomyRequestForm(void);

	RobotomyRequestForm(const std::string);

	RobotomyRequestForm(const RobotomyRequestForm &);

	~RobotomyRequestForm(void);

	RobotomyRequestForm &operator=(const RobotomyRequestForm &);

	void execute(Bureaucrat const &executor) const;
private:
	static bool _success;
};

#endif
