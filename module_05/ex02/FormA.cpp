#include "FormA.hpp"

// CONSTRUCTORS

FormA::FormA()
		: _name("DefaultForm"), _isSigned(false),
		_gradeToSign(1), _gradeToExecute(1)
	{}

FormA::FormA(std::string const newName,
	int newGradeToSign, int newGradeToExecute)
		: _name(newName), _isSigned(false),
		_gradeToSign(newGradeToSign), _gradeToExecute(newGradeToExecute)
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

FormA::FormA(FormA const &source)
		: _name(source.getName()), _isSigned(source.getIsSigned()),
		_gradeToSign(source.getGradeToSign()),
		_gradeToExecute(source.getGradeToExecute())
	{}

// DESTRUCTOR

FormA::~FormA() {}

// OPERATORS

FormA &FormA::operator=(FormA const &source)
{
	this->_isSigned = source.getIsSigned();
	this->_gradeToSign = source.getGradeToSign();
	this->_gradeToExecute = source.getGradeToExecute();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const FormA &form)
{
	out << "Form " << form.getName() << ":\n\tsigned: " << form.getIsSigned()
		<< ",\n\tgrade to sign: " << form.getGradeToSign()
		<< ",\n\tgrade to execute: " << form.getGradeToExecute();
	return (out);
}

// MEMBER FUNCTIONS

std::string const FormA::getName() const
{
	return (this->_name);
}

bool FormA::getIsSigned() const
{
	return (this->_isSigned);
}

int FormA::getGradeToSign() const
{
	return (this->_gradeToSign);
}

int FormA::getGradeToExecute() const
{
	return (this->_gradeToExecute);
}

void FormA::beSigned(const Bureaucrat bureaucrat)
{
	if (bureaucrat.getGrade() > this->_gradeToSign)
	{
		throw GradeTooLowException();
	}
	this->_isSigned = true;
}

// EXCEPTIONS

const char *FormA::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade too low!");
}

const char *FormA::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade too high!");
}
