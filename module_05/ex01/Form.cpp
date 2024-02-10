#include "Form.hpp"

// CONSTRUCTORS

Form::Form()
		: _name("DefaultForm"), _isSigned(false),
		_gradeToSign(1), _gradeToExecute(1)
	{}

Form::Form(std::string const newName,
	int newGradeToSign, int newGradeToExecute)
		: _name(newName), _isSigned(false)
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

Form::Form(Form const &source)
		: _name(source.getName()), _isSigned(source.getIsSigned()),
		_gradeToSign(source.getGradeToSign()),
		_gradeToExecute(source.getGradeToExecute())
	{}

// DESTRUCTOR

Form::~Form() {}

// OPERATORS

Form &Form::operator=(Form const &source)
{
	this->_isSigned = source.getIsSigned();
	this->_gradeToSign = source.getGradeToSign();
	this->_gradeToExecute = source.getGradeToExecute();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Form const &form)
{
	out << "Form " << form.getName() << ":\n\tsigned: " << form.getIsSigned()
		<< ",\n\tgrade to sign: " << form.getGradeToSign()
		<< ",\n\tgrade to execute: " << form.getGradeToExecute();
	return (out);
}

// MEMBER FUNCTIONS

std::string const Form::getName() const
{
	return (this->_name);
}

bool Form::getIsSigned() const
{
	return (this->_isSigned);
}

int Form::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int Form::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void Form::beSigned(Bureaucrat const &bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

// EXCEPTIONS

const char *Form::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade too low!");
}

const char *Form::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade too high!");
}
