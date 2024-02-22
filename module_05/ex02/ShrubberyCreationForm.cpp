#include "ShrubberyCreationForm.hpp"

ShrubberyCreationForm::ShrubberyCreationForm()
	: ShrubberyCreationForm("DefaultTarget") {}

ShrubberyCreationForm::ShrubberyCreationForm(std::string newTarget)
	: AForm("ShrubberyCreationForm", 145, 137, newTarget) {}

ShrubberyCreationForm::ShrubberyCreationForm(ShrubberyCreationForm const &source) : AForm(source) {}

ShrubberyCreationForm::~ShrubberyCreationForm() {}

ShrubberyCreationForm &ShrubberyCreationForm::operator=(ShrubberyCreationForm const &source)
{
	AForm::operator=(source);
	return (*this);
}

void ShrubberyCreationForm::execute(Bureaucrat const &executor) const
{
	if (executor.getGrade() > this->getGradeToExecute())
	{
		throw GradeTooLowException();
	}
	std::ofstream file(this->getTarget() + "_shrubbery");
	if (!file) {
		throw FileCreationFailException();
	}
	file << "               ,@@@@@@@,\n";
	file << "       ,,,.   ,@@@@@@/@@,  .oo8888o.\n";
	file << "    ,&%%&%&&%,@@@@@/@@@@@@,8888\\88/8o\n";
	file << "   ,%&\\%&&%&&%,@@@\\@@@/@@@88\\88888/88'\n";
	file << "   %&&%&%&/%&&%@@\\@@/ /@@@88888\\88888'\n";
	file << "   %&&%/ %&%%&&@@\\ V /@@' `88\\8 `/88'\n";
	file << "   `&%\\ ` /%&'    |.|        \\ '|8'\n";
	file << "       |o|        | |         | |\n";
	file << "       |.|        | |         | |\n";
	file << "_/_ \\\\/ ._\\//_/__/  ,\\_//__\\/.  \\_//__/_";
	file.close();
}

const char *ShrubberyCreationForm::FileCreationFailException::what() const throw()
{
	return ("ERROR: Creating shrubbery file failed 🍂");
}
