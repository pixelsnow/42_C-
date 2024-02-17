#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		std::cout << "Creating a default Bureaucrat" << std::endl;
		Bureaucrat	bureaucratDefault;
		std::cout << bureaucratDefault << std::endl;
		bureaucratDefault.incrementGrade();
		std::cout << "After incrementing: " << bureaucratDefault << std::endl;
		bureaucratDefault.decrementGrade();
		std::cout << "After decrementing: " << bureaucratDefault << std::endl;
		std::cout << "Creating a new Bureaucrat with a non-default constructor" << std::endl;
		Bureaucrat	newBeuraucrat("NewBureaucrat", 22);
		std::cout << newBeuraucrat << std::endl;
		std::cout << "Assigning new Bureaucrat to the default Bureaucrat" << std::endl;
		bureaucratDefault = newBeuraucrat;
		std::cout << "Default Bureaucrat after assignment:" << std::endl;
		std::cout << bureaucratDefault << std::endl;
		std::cout << "Creating a copy of the new Bureaucrat with a copy constructor" << std::endl;
		Bureaucrat	bureaucratCopy(newBeuraucrat);
		std::cout << bureaucratCopy << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Trying to create a Bureaucrat with grade 151" << std::endl;
		Bureaucrat	bureaucratTooLow("TooLow", 151);
		std::cout << bureaucratTooLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Trying to create a Bureaucrat with grade 0" << std::endl;
		Bureaucrat	bureaucratTooHigh("TooHigh", 0);
		std::cout << bureaucratTooHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Creating a Bureaucrat with grade 150" << std::endl;
		Bureaucrat	bureaucratLow("Low", 150);
		std::cout << bureaucratLow << std::endl;
		std::cout << "Trying to decrement grade to 151" << std::endl;
		bureaucratLow.decrementGrade();
		std::cout << bureaucratLow << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	std::cout << std::endl;
	try
	{
		std::cout << "Creating a Bureaucrat with grade 1" << std::endl;
		Bureaucrat	bureaucratHigh("High", 1);
		std::cout << bureaucratHigh << std::endl;
		std::cout << "Trying to increment grade to 0" << std::endl;
		bureaucratHigh.incrementGrade();
		std::cout << bureaucratHigh << std::endl;
	}
	catch (std::exception &e)
	{
		std::cerr << e.what() << std::endl;
	}
	return (0);
}
