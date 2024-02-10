#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: ShrubberyCreationForm("DefaultTarget")
{}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
	: AForm("ShrubberyCreationForm", 145, 137, newTarget)
{
	std::cout << "target is " << this->getTarget() << std::endl;
}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) : AForm(source) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	AForm::operator=(source);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	// TODO: refactor to move grade check to the base class
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file) {
		throw FileCreationFailException();
	}
	file << "               ,@@@@@@@,";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'";
	file << "       |o|        | |         | |";
	file << "       |.|        | |         | |";
	file << "_/_ \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
	file << std::endl;
	file.close();
}

const char *ShrubberyCreationForm::FileCreationFailException::what() const throw()
{
	return ("ERROR: Creating shrubbery failed 🍂");
}
