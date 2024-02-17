#include "Intern.hpp"

const FormMatch Intern::formMatch[] =
{
	{ "shrubbery", &Intern::createShrubberyForm },
	{ "robotomy", &Intern::createRobotomyForm },
	{ "presidential", &Intern::createPresidentialForm },
};

// CONSTRUCTORS

Intern::Intern() {}

Intern::Intern(Intern const &source)
{
	(void) source;
}

// DESTRUCTOR

Intern::~Intern() {}

// OPERATORS

Intern &Intern::operator=(Intern const &source)
{
	(void) source;
	return (*this);
}

// MEMBER FUNCTIONS

AForm* Intern::createShrubberyForm(std::string const formTarget)
{
	return new ShrubberyCreationForm(formTarget);
}

AForm* Intern::createRobotomyForm(std::string const formTarget)
{
	return new RobotomyRequestForm(formTarget);
}

AForm* Intern::createPresidentialForm(std::string const formTarget)
{
	return new PresidentialPardonForm(formTarget);
}

AForm *Intern::makeForm(std::string const formName, std::string const formTarget) const
{
	for (int i = 0; i < NUM_FORM_TYPES; i++)
	{
		if (formName == formMatch[i].formName)
			return ((*(formMatch[i].formConstructorPtr))(formTarget));
	}
	throw WrongFormNameException();
}

// EXCEPTIONS

const char *Intern::WrongFormNameException::what() const throw()
{
	return ("No such form exists •`_´•");
}
