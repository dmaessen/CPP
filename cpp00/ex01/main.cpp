#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook book;
	std::string cmd;

	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH and EXIT" << '\n';
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			book.cmd_add();
		// if (cmd == "SEARCH")
			//book.cmd_search(); // two phases: 1- display whole phonebook 2- ask for an index
		if (cmd == "EXIT")
			exit(1);
	}
	return 0;
}