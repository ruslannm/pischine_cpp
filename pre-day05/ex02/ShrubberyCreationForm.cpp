#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm(void) : AForm("Undefined", 145,
														   137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const std::string name) : AForm(
		name, 145, 137) {};

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &src)
		: AForm(src.getName(), 145, 137) {};

ShrubberyCreationForm::~ShrubberyCreationForm(void) {};

ShrubberyCreationForm &
ShrubberyCreationForm::operator=(const ShrubberyCreationForm &rhs)
{
	if (this != &rhs)
	{
		this->AForm::operator=(rhs);
	}
	return *this;
}


void ShrubberyCreationForm::execute(Bureaucrat const &bureaucrat) const
{
	AForm::execute(bureaucrat);
	std::ofstream ofs;

	ofs.open(this->getName() + "_shrubbery");
	if (ofs)
	{
		ofs <<
			"      /\\" << std::endl <<
			"     /\\*\\" << std::endl <<
			"    /\\O\\*\\" << std::endl <<
			"   /*/\\/\\/\\" << std::endl <<
			"  /\\O\\/\\*\\/\\" << std::endl <<
			" /\\*\\/\\*\\/\\/\\" << std::endl <<
			"/\\O\\/\\/*/\\/O/\\" << std::endl <<
			"      ||" << std::endl <<
			"      ||" << std::endl <<
			"      ||" << std::endl;
		ofs.close();
		return;
	}
	else
	{
		std::cerr << "cannot create " << this->getName() << "_shrubbery"
				  << " file" << std::endl;
		return;
	}
}

