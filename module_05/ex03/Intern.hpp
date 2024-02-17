#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>
#include "AForm.hpp"
#include "ShrubberyCreationForm.hpp"
#include "PresidentialPardonForm.hpp"
#include "RobotomyRequestForm.hpp"

#define NUM_FORM_TYPES 3

struct FormMatch
{
	std::string formName;
	AForm* (*formConstructorPtr)(std::string const);
};

class Intern
{
	private:
		static const FormMatch formMatch[];
		static AForm* createShrubberyForm(std::string const formTarget);
		static AForm* createRobotomyForm(std::string const formTarget);
		static AForm* createPresidentialForm(std::string const formTarget);
	public:
		Intern();
		Intern(Intern const &source);
		~Intern();

		Intern &operator=(Intern const &source);

		AForm* makeForm(std::string const formName, std::string const formTarget) const;

		class WrongFormNameException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
