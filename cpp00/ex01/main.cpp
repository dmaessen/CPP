#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

// void cmd_search()
// {
	
// }

int main(void)
{
	PhoneBook book;
	std::string cmd;

	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH and EXIT" << '\n';
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			cmd_add();
		// if (cmd == "SEARCH")
			//cmd_search(); // two phases: 1- display whole phonebook 2- ask for an index
		if (cmd == "EXIT")
			break ;
	}
	// something to clean up here??
	return 0;
}