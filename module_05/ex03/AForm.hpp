#ifndef AForm_HPP
#define AForm_HPP

#include "consts.hpp"
#include <iostream>
#include <cstdbool>
#include "Bureaucrat.hpp"
class Bureaucrat;

class AForm
{
	private:
		std::string const _name;
		bool _isSigned;
		int _gradeToSign;
		int _gradeToExecute;
		std::string _target;
	public:
		AForm();
		AForm(std::string const newName, int newGradeToSign, int newGradeToExecute, std::string const newTarget);
		AForm(AForm const &source);
		~AForm();

		AForm &operator=(AForm const &source);

		std::string const getName() const;
		bool getIsSigned() const;
		int getGradeToSign() const;
		int getGradeToExecute() const;
		std::string const getTarget() const;

		void beSigned(Bureaucrat const &bureaucrat);
		virtual void execute(Bureaucrat const &executor) const = 0;

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

std::ostream &operator<<(std::ostream &out, AForm const &form);

#endif
