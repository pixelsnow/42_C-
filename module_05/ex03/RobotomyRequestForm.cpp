#include "RobotomyRequestForm.hpp"

RobotomyRequestForm::RobotomyRequestForm()
	: RobotomyRequestForm("DefaultTarget") {}

RobotomyRequestForm::RobotomyRequestForm(std::string newTarget)
	: AForm("RobotomyRequestForm", 72, 45, newTarget) {}

RobotomyRequestForm::RobotomyRequestForm(RobotomyRequestForm const &source) : AForm(source) {}

RobotomyRequestForm::~RobotomyRequestForm() {}

RobotomyRequestForm &RobotomyRequestForm::operator=(RobotomyRequestForm const &source)
{
	AForm::operator=(source);
	return (*this);
}

void RobotomyRequestForm::execute(Bureaucrat const &executor) const
{
	// TODO: refactor to move grade check to the base class	
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::string drilling = "* drilling noises *";
	for (unsigned int i = 0; i < drilling.length(); i++)
	{
		std::cout << drilling[i] << std::flush;
		usleep(50000);
	}
	std::cout << std::endl << std::flush;
	usleep(500000);
	srand(time(NULL));
	if (rand() % 2)
	{
		std::cout << this->getTarget() << " has been robotomized successfully" << std::endl;
	}
	else
	{
		std::cout << "Robotomy failed :(" << std::endl;
	}
}
