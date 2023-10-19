#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	bool		exit;
	std::string	command;

	exit = false;
	phonebook.printInstructions();
	while (!exit)
	{
		std::getline(std::cin, command);
		std::transform(command.begin(), command.end(), command.begin(),
				::tolower);
		if (command == "exit")
			exit = true;
		else if (command == "add")
			phonebook.add();
		else if (command == "search")
			phonebook.search();
		else
			phonebook.printInstructions();
	}
	return 0;
}
