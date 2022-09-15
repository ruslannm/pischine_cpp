#ifndef FORM_HPP
#define FORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
public:
	Form(void);

	Form(std::string const, int const, int const);

	Form(const Form &);

	~Form(void);

	Form &operator=(const Form &);

	std::string getName(void) const;

	bool getIsSigned(void) const;

	int getGradeToSign(void) const;

	int getGradeToExecute(void) const;

	void beSigned(const Bureaucrat &);

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

private:
	std::string const _name;
	bool _isSigned;
	int const _gradeToSign;
	int const _gradeToExecute;
};

std::ostream &operator<<(std::ostream &, const Form &);

#endif
