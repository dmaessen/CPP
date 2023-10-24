#include "Contact.h"
#include "Phonebook.h"
#include <iostream>
#include <string.h>

void cmd_add()
{
	// initalise the list..
	Contact new{};  // how does this work?? Create new contact

	std::cout << "First name: ";
	new.getFirstName(FirstName);
	std::cin >> new.FirstName; // cannot be empty
	std::cout << new.FirstName << '\n';

	std::cout << "Last name: ";

	std::cout << "Nickname: ";

	std::cout << "Phone number: ";

	std::cout << "Darkest secret: ";


	std::array<std::string, 5> Contact new;

	// {FirstName, LastName, Nickname, PhoneNb, Secret};

	//maybe extra field to see which contact has been added last for overwritting??
}

void cmd_search()
{
	
}

int main(int argc, char **argv)
{
	while (1)
	{
		std::cout << "phonebook:";// ft to display new prompt each time
		if (argc != 2)
			std::cout << "Try again, available commands: ADD, SEARCH and EXIT" << '\n';
		else if (strcmp(argv[1], "ADD") == 0)
			cmd_add(); // show all available fileds to be filled in 
		else if (strcmp(argv[1], "SEARCH") == 0)
			// two phases: 1- display whole phonebook 2- ask for an index
		else if (strcmp(argv[1], "EXIT") == 0)
			break ;
		else
			std::cout << "Try again, available commands: ADD, SEARCH and EXIT" << '\n'; // display new prompt
	}
	// here clean up all 
}