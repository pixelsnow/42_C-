#include "PhoneBook.hpp"

int main(void)
{
	PhoneBook	phonebook;
	bool		exit;
	char		command[10];

	exit = false;
	phonebook.printInstructions();
	while (!exit)
	{
		std::cin >> command;
		std::cout << "Your command: " << command << std::endl;
		if (!strcmp(command, "exit"))
			exit = true;
		phonebook.run();
	}
	return 0;
}