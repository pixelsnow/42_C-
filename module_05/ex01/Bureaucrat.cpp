#include "Bureaucrat.hpp"

// CONSTRUCTORS

Bureaucrat::Bureaucrat() : _name("DefaultBureaucrat"), _grade(LOWEST_GRADE) {}

Bureaucrat::Bureaucrat(std::string const newName, int newGrade) : _name(newName)
{
	if (newGrade < HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	if (newGrade > LOWEST_GRADE)
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
	if (this == &source)
		return (*this);
	this->_grade = source.getGrade();
	return (*this);
}

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat)
{
	out << bureaucrat.getName() << ", bureaucrat grade " << bureaucrat.getGrade() << ".";
	return (out);
}

// MEMBER FUNCTIONS

std::string const Bureaucrat::getName() const
{
	return (this->_name);
}

int Bureaucrat::getGrade() const
{
	return (this->_grade);
}

void Bureaucrat::incrementGrade()
{
	if (this->_grade == HIGHEST_GRADE)
	{
		throw GradeTooHighException();
	}
	this->_grade--;
}

void Bureaucrat::decrementGrade()
{
	if (this->_grade == LOWEST_GRADE)
	{
		throw GradeTooLowException();
	}
	this->_grade++;
}

void Bureaucrat::signForm(Form &form) const
{
	try
	{
		form.beSigned(*this);
		std::cout << this->_name << " signed " << form.getName() << std::endl;
	}
	catch(const std::exception& e)
	{
		std::cerr << this->_name << " couldn’t sign " << form.getName() << " because " << e.what() << std::endl;
	}
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
