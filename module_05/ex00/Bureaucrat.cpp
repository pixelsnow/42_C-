#include "Bureaucrat.hpp"

// CONSTRUCTORS

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const newName, int newGrade) : _name(newName)
{
	if (newGrade < 1)
	{
		throw GradeTooHighException();
	}
	if (newGrade > 150)
	{
		throw GradeTooLowException();
	}
	this->_grade = newGrade;
}

Bureaucrat::Bureaucrat(Bureaucrat const &source) : _name(source.getName()), _grade(source.getGrade()) {}

// DESTRUCTOR

Bureaucrat::~Bureaucrat() {}

// OPERATORS

Bureaucrat &Bureaucrat::operator=(Bureaucrat const &source)
{
	this->_grade = source.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return out;
}

// MEMBER FUNCTIONS

std::string const Bureaucrat::getName() const
{
	return this->_name;
}

int Bureaucrat::getGrade() const
{
	return this->_grade;
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == 1)
	{
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == 150)
	{
		throw GradeTooLowException();
	}
	this->_grade++;
}

// EXCEPTIONS

const char *Bureaucrat::GradeTooHighException::what() const throw()
{
	return ("ERROR: Grade too high!");
}

const char *Bureaucrat::GradeTooLowException::what() const throw()
{
	return ("ERROR: Grade too low!");
}
