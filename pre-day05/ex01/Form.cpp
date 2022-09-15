#include "Form.hpp"

Form::Form(void) : _name("Undefined"), _isSigned(false), _gradeToSign(1),
				   _gradeToExecute(1) {};

Form::Form(std::string const name, int const gradeToSign,
		   int const gradeToExecute) : _name(name), _isSigned(false),
									   _gradeToSign(gradeToSign),
									   _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw Form::GradeTooHighException();
	}

	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw Form::GradeTooLowException();
	}
	return;
}

Form::Form(const Form &src) : _name(src._name), _isSigned(false),
							  _gradeToSign(src._gradeToSign),
							  _gradeToExecute(src._gradeToExecute) {};

Form::~Form(void) {};

Form &Form::operator=(const Form &rhs)
{
	if (this != &rhs)
	{
		std::string *_namePTR = (std::string * ) & (this->_name);
		int *_gradeToSignPTR = (int *) &(this->_gradeToSign);
		int *_gradeToExecutePTR = (int *) &(this->_gradeToExecute);

		*_namePTR = rhs._name;
		*_gradeToSignPTR = rhs._gradeToSign;
		*_gradeToExecutePTR = rhs._gradeToExecute;
	}
	return *this;
}

std::string Form::getName(void) const { return _name; };

bool Form::getIsSigned(void) const { return _isSigned; };

int Form::getGradeToSign() const { return _gradeToSign; };

int Form::getGradeToExecute() const { return _gradeToExecute; };

void Form::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw Form::GradeTooLowException();
	}
	else
	{
		_isSigned = true;
	}
	return;
}

const char *Form::GradeTooHighException::what(void) const throw()
{
	return "Grade to high!";
}

const char *Form::GradeTooLowException::what(void) const throw()
{
	return "Grade to low!";
}

std::ostream &operator<<(std::ostream &o, const Form &form)
{
	o << "Form name: " << form.getName() << ", is signed: "
	  << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign()
	  << ", grade to execute: " << form.getGradeToExecute();
	return o;
}