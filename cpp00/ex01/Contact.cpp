#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>

void cmd_add()
{
	Contact newcontact;  // how does this work?? Create new contact
	std::string input;
	
	std::cout << "First name: ";
	std::getline(std::cin, newcontact->setFirstName(input)); // how does this work?
		// check if empty, as cannot be
	std::cout << "\n";

	std::cout << "Last name: ";
	std::getline(std::cin, newcontact->setLastName(input));
		// check if empty, as cannot be
	std::cout << "\n";

	std::cout << "Nickname: ";
	std::getline(std::cin, newcontact->setNickname(input));
		// check if empty, as cannot be
	std::cout << "\n";

	std::cout << "Phone number: ";
	std::getline(std::cin, newcontact->setPhoneNb(input));
		// check if empty, as cannot be
	std::cout << "\n";

	std::cout << "Darkest secret: ";
	std::getline(std::cin, newcontact->setSecret(input));
		// check if empty, as cannot be
	std::cout << "\n";
    print_contactinfo(newcontact);
	// maybe extra field to see which contact has been added last for overwritting??
	// now add new to the phonebook list, checking if it needs to overwrite the oldest
}

void print_contactinfo(Contact newcontact)
{
    std::cout << newcontact.getFirstName() << '\n'; // do i need newcontact here?? bit confused
    std::cout << newcontact.getLastName() << '\n';
    std::cout << newcontact.getNickname() << '\n';
    std::cout << newcontact.getPhoneNb() << '\n';
    std::cout << newcontact.getSecret() << '\n';
}

// void setContact(std::string FirstName, std::string LastName, std::string Nickname, std::string PhoneNb, std::string Secret)
// {
//     Contact newcontact; // with or without brackets??

//     newcontact->m_FirstName = FirstName;
//     newcontact->m_LastName = LastName;
//     newcontact->m_Nickname = Nickname;
//     newcontact->m_PhoneNb = PhoneNb;
//     newcontact->m_Secret = Secret;
// }