#include "Bureaucrat.hpp"
#include "Form.hpp"

int main(void)
{
	try
	{
		Bureaucrat	internBureaucrat("InternBureaucrat", 150);
		std::cout << internBureaucrat << std::endl;
		Bureaucrat	CEOBureaucrat("CEOBureaucrat", 1);
		std::cout << CEOBureaucrat << std::endl;
		Form form("VeryImportantForm", 20, 10);
		std::cout << form << std::endl;
		CEOBureaucrat.signForm(form);
		std::cout << form << std::endl;
		Form otherForm("OtherVeryImportantForm", 20, 10);
		std::cout << otherForm << std::endl;
		internBureaucrat.signForm(otherForm);
		std::cout << otherForm << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
