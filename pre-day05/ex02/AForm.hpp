#ifndef AFORM_HPP
#define AFORM_HPP

#include <iostream>
#include <string>

#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
public:
	AForm(void);

	AForm(std::string const, int const, int const);

	AForm(const AForm &);

	virtual ~AForm(void);

	AForm &operator=(const AForm &);

	std::string getName(void) const;

	bool getIsSigned(void) const;

	int getGradeToSign(void) const;

	int getGradeToExecute(void) const;

	void beSigned(const Bureaucrat &);

	virtual void execute(Bureaucrat const &) const = 0;

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

	class ExecutionIsNotAllowedException : public std::exception
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

std::ostream &operator<<(std::ostream &, const AForm &);

#endif
