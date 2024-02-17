#include "PresidentialPardonForm.hpp"

PresidentialPardonForm::PresidentialPardonForm()
	: PresidentialPardonForm("DefaultTarget") {}

PresidentialPardonForm::PresidentialPardonForm(std::string newTarget)
	: AForm("PresidentialPardonForm", 25, 5, newTarget) {}

PresidentialPardonForm::PresidentialPardonForm(PresidentialPardonForm const &source) : AForm(source) {}

PresidentialPardonForm::~PresidentialPardonForm() {}

PresidentialPardonForm &PresidentialPardonForm::operator=(PresidentialPardonForm const &source)
{
	AForm::operator=(source);
	return (*this);
}

void PresidentialPardonForm::execute(Bureaucrat const &executor) const
{
	// TODO: refactor to move grade check to the base class
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::cout << this->getTarget() << " has been pardoned by Zaphod Beeblebrox" << std::endl;
}
