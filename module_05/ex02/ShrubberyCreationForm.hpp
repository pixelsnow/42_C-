#ifndef SHRUBBERY_CREATION_FORM_HPP
#define SHRUBBERY_CREATION_FORM_HPP

#include "AForm.hpp"
#include <fstream>

class ShrubberyCreationForm : public AForm
{
	public:
		ShrubberyCreationForm();
		ShrubberyCreationForm(std::string newTarget);
		ShrubberyCreationForm(ShrubberyCreationForm const &source);
		~ShrubberyCreationForm();

		ShrubberyCreationForm &operator=(ShrubberyCreationForm const &source);

		void execute(Bureaucrat const &executor) const;

		class FileCreationFailException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

#endif
