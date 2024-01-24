#include "Bureaucrat.hpp"

Bureaucrat::Bureaucrat() : _name("Nameless"), _grade(150) {}

Bureaucrat::Bureaucrat(std::string const newName, int newGrade) : name(newName)
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