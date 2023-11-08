#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>

int main(void)
{
	PhoneBook book;
	std::string cmd;

	book.init();
	while (1)
	{
		std::cout << "Available commands: ADD, SEARCH and EXIT" << '\n';
		std::getline(std::cin, cmd);
		if (cmd == "ADD")
			book.cmd_add();
		if (cmd == "SEARCH")
			book.cmd_search();
		if (cmd == "EXIT")
			break ;
	}
	return 0;
}