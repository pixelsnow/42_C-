#ifndef FORM_HPP
#define FORM_HPP

#include "consts.hpp"
#include <iostream>
#include <cstdbool>
#include "Bureaucrat.hpp"
class Bureaucrat;

class Form
{
	private:
		std::string const _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;
	public:
		Form();
		Form(std::string const newName, int newGradeToSign, int newGradeToExecute);
		Form(Form const &source);
		~Form();

		Form &operator=(Form const &source);

		std::string const getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(Bureaucrat const &bureaucrat);

		class GradeTooLowException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
		class GradeTooHighException: public std::exception
		{
			public:
				virtual const char *what() const throw();
		};
};

std::ostream &operator<<(std::ostream &out, Form const &form);

#endif
