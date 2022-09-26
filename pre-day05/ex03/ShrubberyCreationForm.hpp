#ifndef SHRUBBERYCREATIONFORM_HPP
#define SHRUBBERYCREATIONFORM_HPP

# include <iostream>
# include <fstream>
# include "AForm.hpp"

class ShrubberyCreationForm : public AForm
{
public:
	ShrubberyCreationForm(void);

	ShrubberyCreationForm(const std::string);

	ShrubberyCreationForm(const ShrubberyCreationForm &);

	~ShrubberyCreationForm(void);

	ShrubberyCreationForm &operator=(const ShrubberyCreationForm &);

	void execute(Bureaucrat const &executor) const;
};

#endif
