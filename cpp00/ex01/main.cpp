#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string.h>

// void cmd_search()
// {
	
// }

int main(void)
{
	// PhoneBook PhoneBook();
	std::string cmd;

	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH and EXIT" << '\n';
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			cmd_add(); // show all available fileds to be filled in 
		if (cmd == "SEARCH")
			//cmd_search(); // two phases: 1- display whole phonebook 2- ask for an index
		if (cmd == "EXIT")
			break ;
	}
	// something to clean up here??
	return 0;
}