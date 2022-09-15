#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat(void) : _name("Undefined"), _grade(150) {};

Bureaucrat::Bureaucrat(const std::string &name) : _name(name), _grade(150) {};

Bureaucrat::Bureaucrat(const std::string &name, int grade) : _name(name)
{
	if (grade < 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	if (grade > 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	this->_grade = grade;
	return;
};

Bureaucrat::Bureaucrat(const Bureaucrat &src) : _name(src._name),
												_grade(src._grade) {};

Bureaucrat &Bureaucrat::operator=(const Bureaucrat &rhs)
{
	if (this != &rhs)
	{
		this->_grade = rhs._grade;
	}
	return *this;
};

Bureaucrat::~Bureaucrat(void) {};

int Bureaucrat::getGrade(void) const
{
	return _grade;
};

std::string Bureaucrat::getName(void) const
{
	return _name;
};

void Bureaucrat::increaseGrade(void)
{
	if (_grade == 1)
	{
		throw (Bureaucrat::GradeTooHighException());
	}
	else
	{
		--_grade;
	}
	return;
};

void Bureaucrat::decreaseGrade(void)
{
	if (_grade == 150)
	{
		throw (Bureaucrat::GradeTooLowException());
	}
	else
	{
		++_grade;
	}
	return;
};

const char *Bureaucrat::GradeTooHighException::what(void) const throw()
{
	return ("Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what(void) const throw()
{
	return ("Grade too low!");
}

std::ostream &operator<<(std::ostream &o, const Bureaucrat &ref)
{
	o << ref.getName() << ", bureaucrat grade " << ref.getGrade();
	return o;
}