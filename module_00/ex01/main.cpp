#include "PhoneBook.hpp"

/* std::string toLower(std::string str)
{
	return str;
} */

int main(void)
{
	PhoneBook	phonebook;
	bool		exit;
	std::string	command;

	exit = false;
	phonebook.printInstructions();
	while (!exit)
	{
		std::cin >> command;
		std::transform(command.begin(), command.end(), command.begin(),
				::tolower);
		if (command == "exit")
			exit = true;
		else if (command == "add")
			phonebook.run();
		else
			phonebook.printInstructions();
	}
	return 0;
}
