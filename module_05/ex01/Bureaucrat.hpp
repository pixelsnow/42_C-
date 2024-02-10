#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP

#include "consts.hpp"
#include <iostream>
#include "Form.hpp"
class Form;

class Bureaucrat
{
	private:
		std::string const _name;
		int _grade;
	public:
		Bureaucrat();
		Bureaucrat(std::string const newName, int newGrade);
		Bureaucrat(Bureaucrat const &source);
		~Bureaucrat();

		Bureaucrat &operator=(Bureaucrat const &source);

		std::string const getName() const;
		int getGrade() const;
		void incrementGrade();
		void decrementGrade();

		void signForm(Form &form) const;

		class GradeTooHighException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooLowException : public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Bureaucrat const &bureaucrat);

#endif
