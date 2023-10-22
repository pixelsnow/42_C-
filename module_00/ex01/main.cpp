#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	std::string	command;

	while (std::getline(std::cin, command))
	{
		std::transform(command.begin(), command.end(), command.begin(),
				::tolower);
		if (command == "exit")
			break;
		else if (command == "add")
			phonebook.add();
		else if (command == "search")
			phonebook.search();
		else
			phonebook.printInstructions();
	}
	return 0;
}
