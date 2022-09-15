#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include <iostream>
#include <string>

class Bureaucrat
{

public:
	Bureaucrat(void);

	Bureaucrat(const std::string &);

	Bureaucrat(const std::string &, int);

	Bureaucrat(const Bureaucrat &);

	Bureaucrat &operator=(const Bureaucrat &);

	~Bureaucrat(void);

	int getGrade(void) const;

	std::string getName(void) const;

	void increaseGrade(void);

	void decreaseGrade(void);

	class GradeTooHighException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

	class GradeTooLowException : public std::exception
	{
	public:
		virtual const char *what(void) const throw();
	};

private:
	std::string const _name;
	int _grade;
};

std::ostream &operator<<(std::ostream &, const Bureaucrat &);

#endif
