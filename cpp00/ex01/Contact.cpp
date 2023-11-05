#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

//void Contact::getinfo()




void cmd_add()
{
	Contact newcontact;
	std::string input;
	// index needed ??
	
	std::cout << "First name: ";
	std::getline(std::cin, input); // check if empty, as cannot be
	newcontact.setFirstName(input);
	std::cout << "\n";

	std::cout << "Last name: ";
	std::getline(std::cin, input); // check if empty, as cannot be
	newcontact.setLastName(input);
	std::cout << "\n";

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	newcontact.setNickname(input);
	std::cout << "\n";

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	newcontact.setPhoneNb(input);
	std::cout << "\n";

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	newcontact.setSecret(input);
	std::cout << "\n";

    print_contactinfo(newcontact);
	// maybe extra field to see which contact has been added last for overwritting??
	// now add new to the phonebook list, checking if it needs to overwrite the oldest
}

void Contact::print_contactinfo(Contact newcontact)
{
    std::cout << newcontact.getFirstName() << '\n'; // do i need newcontact here?? bit confused
    std::cout << newcontact.getLastName() << '\n';
    std::cout << newcontact.getNickname() << '\n';
    std::cout << newcontact.getPhoneNb() << '\n';
    std::cout << newcontact.getSecret() << '\n';
}

