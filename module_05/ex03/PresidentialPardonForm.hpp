#ifndef PRESIDENTIAL_PARDON_FORM_HPP
#define PRESIDENTIAL_PARDON_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class PresidentialPardonForm : public AForm
{
	public:
		PresidentialPardonForm();
		PresidentialPardonForm(std::string newTarget);
		PresidentialPardonForm(PresidentialPardonForm const &source);
		~PresidentialPardonForm();

		PresidentialPardonForm &operator=(PresidentialPardonForm const &source);

		void execute(Bureaucrat const &executor) const;
};

#endif
