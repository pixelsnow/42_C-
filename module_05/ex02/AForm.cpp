#include "AForm.hpp"

// CONSTRUCTORS

AForm::AForm()
		: _name("DefaultForm"), _isSigned(false),
		_gradeToSign(1), _gradeToExecute(1)
	{}

AForm::AForm(std::string const newName,
	int newGradeToSign, int newGradeToExecute, std::string const newTarget)
		: _name(newName), _isSigned(false), _target(newTarget)
	{
		if (newGradeToSign > LOWEST_GRADE || newGradeToExecute > LOWEST_GRADE)
		{
			throw GradeTooLowException();
		}
		if (newGradeToSign < HIGHEST_GRADE || newGradeToExecute < HIGHEST_GRADE)
		{
			throw GradeTooHighException();
		}
		this->_gradeToSign = newGradeToSign;
		this->_gradeToExecute = newGradeToExecute;
	}

AForm::AForm(AForm const &source)
		: _name(source.getName()), _isSigned(source.getIsSigned()),
		_gradeToSign(source.getGradeToSign()),
		_gradeToExecute(source.getGradeToExecute()),
		_target(source.getTarget())
	{}

// DESTRUCTOR

AForm::~AForm() {}

// OPERATORS

AForm &AForm::operator=(AForm const &source)
{
	this->_isSigned = source.getIsSigned();
	this->_gradeToSign = source.getGradeToSign();
	this->_gradeToExecute = source.getGradeToExecute();
	this->_target = source.getTarget();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, AForm const &form)
{
	out << "Form " << form.getName() << ":\n\tsigned: " << form.getIsSigned()
		<< ",\n\tgrade to sign: " << form.getGradeToSign()
		<< ",\n\tgrade to execute: " << form.getGradeToExecute();
	return (out);
}

// MEMBER FUNCTIONS

std::string const AForm::getName() const
{
	return (this->_name);
}

bool AForm::getIsSigned() const
{
	return (this->_isSigned);
}

int AForm::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int AForm::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

std::string const AForm::getTarget() const
{
	return (this->_target);
}

void AForm::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

// EXCEPTIONS

const char *AForm::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade too low!");
}

const char *AForm::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade too high!");
}
