#ifndef INTERN_HPP
#define INTERN_HPP

#include <iostream>

class AForm;

class Intern
{
	public:
		Intern();
		Intern(Intern const &source);
		~Intern();

		Intern &operator=(Intern const &source);

		AForm* makeForm(std::string const formName, std::string const formTarget) const;
};

std::ostream &operator<<(std::ostream &out, Intern const &intern);

#endif
