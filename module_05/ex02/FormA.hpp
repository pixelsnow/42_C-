#ifndef FORMA_HPP
#define FORMA_HPP

#include "consts.hpp"
#include <iostream>
#include <cstdbool>
#include "Bureaucrat.hpp"
class Bureaucrat;

class FormA
{
	private:
		std::string const _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;
	public:
		FormA();
		FormA(std::string const newName, int newGradeToSign, int newGradeToExecute);
		FormA(FormA const &source);
		~FormA();

		FormA &operator=(FormA const &source);

		std::string const getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;

		void beSigned(const Bureaucrat bureaucrat);

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

std::ostream &operator<<(std::ostream &out, const FormA &form);

#endif
