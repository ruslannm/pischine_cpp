#include "AForm.hpp"

AForm::AForm(void) : _name("Undefined"), _isSigned(false), _gradeToSign(1),
					 _gradeToExecute(1) {};

AForm::AForm(std::string const name, int const gradeToSign,
			 int const gradeToExecute) : _name(name), _isSigned(false),
										 _gradeToSign(gradeToSign),
										 _gradeToExecute(gradeToExecute)
{
	if (gradeToSign < 1 || gradeToExecute < 1)
	{
		throw AForm::GradeTooHighException();
	}

	if (gradeToSign > 150 || gradeToExecute > 150)
	{
		throw AForm::GradeTooLowException();
	}
	return;
}

AForm::AForm(const AForm &src) : _name(src._name), _isSigned(false),
								 _gradeToSign(src._gradeToSign),
								 _gradeToExecute(src._gradeToExecute) {};

AForm::~AForm(void) {};

AForm &AForm::operator=(const AForm &rhs)
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

std::string AForm::getName(void) const { return _name; };

bool AForm::getIsSigned(void) const { return _isSigned; };

int AForm::getGradeToSign() const { return _gradeToSign; };

int AForm::getGradeToExecute() const { return _gradeToExecute; };

void AForm::beSigned(const Bureaucrat &bureaucrat)
{
	if (bureaucrat.getGrade() > _gradeToSign)
	{
		throw AForm::GradeTooLowException();
	}
	else
	{
		_isSigned = true;
	}
	return;
}

const char *AForm::GradeTooHighException::what(void) const throw()
{
	return "Grade to high!";
}

const char *AForm::GradeTooLowException::what(void) const throw()
{
	return "Grade to low!";
}

const char *AForm::ExecutionIsNotAllowedException::what(void) const throw()
{
	return "Form is not signed. Execution is not allowed!";
}

std::ostream &operator<<(std::ostream &o, const AForm &form)
{
	o << "Form name: " << form.getName() << ", is signed: "
	  << form.getIsSigned() << ", grade to sign: " << form.getGradeToSign()
	  << ", grade to execute: " << form.getGradeToExecute();
	return o;
}

void AForm::execute(Bureaucrat const &bureaucrat) const
{
	if (!getIsSigned())
	{
		throw ExecutionIsNotAllowedException();
	}
	if (bureaucrat.getGrade() > getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	return;
}
