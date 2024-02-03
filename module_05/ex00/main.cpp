#include "Bureaucrat.hpp"

int main(void)
{
	try
	{
		Bureaucrat	bureaucratDefault;
		Bureaucrat	bureaucratTooLow("TooLow", 151);
		Bureaucrat	bureaucratTooHigh("TooHigh", 0);
		Bureaucrat	bureaucratLow("Low", 150);
		Bureaucrat	bureaucratHigh("High", 1);
	}
	catch (std::exception & e)
	{
		std::cout << e.what() << std::endl;
	}

	return (0);
}
