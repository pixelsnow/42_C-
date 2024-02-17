#ifndef ROBOTOMY_REQUEST_FORM_HPP
#define ROBOTOMY_REQUEST_FORM_HPP

#include "AForm.hpp"
#include <fstream>
#include <unistd.h>

class RobotomyRequestForm : public AForm
{
	public:
		RobotomyRequestForm();
		RobotomyRequestForm(std::string newTarget);
		RobotomyRequestForm(RobotomyRequestForm const &source);
		~RobotomyRequestForm();

		RobotomyRequestForm &operator=(RobotomyRequestForm const &source);

		void execute(Bureaucrat const &executor) const;
};

#endif
