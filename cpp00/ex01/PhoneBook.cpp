#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>

void PhoneBook::init()
{
	m_count_contacts = 0;
}

void PhoneBook::cmd_add()
{
	Contact newcontact;
	
	newcontact = getInfo();
	contact[m_count_contacts % 8] = newcontact;
	m_count_contacts += 1;
	std::cout << "contacts amount == " << m_count_contacts % 8 << '\n'; // to rm
}

Contact PhoneBook::getInfo()
{
	Contact newcontact;
	std::string input;

	std::cout << "First name: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setFirstName(input);

	std::cout << "Last name: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setLastName(input);

	std::cout << "Nickname: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setNickname(input);

	std::cout << "Phone number: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setPhoneNb(input);

	std::cout << "Darkest secret: ";
	std::getline(std::cin, input);
	if (input == "")
	{
		std::cout << "Invalid, an input is needed\n";
		do {
			std::getline(std::cin, input);
		}	while (input == "");
	}
	newcontact.setSecret(input);

	std::cout << newcontact.getFirstName() << '\n'; // to rm
    std::cout << newcontact.getLastName() << '\n'; // to rm
    std::cout << newcontact.getNickname() << '\n'; // to rm
    std::cout << newcontact.getPhoneNb() << '\n'; // to rm
    std::cout << newcontact.getSecret() << '\n'; // to rm
	return newcontact;
}

void	PhoneBook::cmd_search()
{
	std::size_t index;
	std::size_t amount;
	std::string	input;

	if (m_count_contacts > 7)
		amount = 8;
	else
		amount = m_count_contacts;
	for (size_t i = 0; i < amount; i++)
	{
		printinfo(contact[i], i);
		// display | index | first name | last name | nickname | --> each column 10char wide, if longer .
		// and right align ++ add the dot
		// resize fucntion for string -- and functions from cout
	}
	std::cout << "Please enter an index: "; // or with new line??
	std::getline(std::cin, input);
	try 
	{
		index = std::stoul(input);
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << ex.what() << '\n';
	}
	if (index < 0 || index > amount - 2) // check on this -2
	{
		std::cout << "Invalid index, try again.\n";
		do {
			std::getline(std::cin, input);
			index = std::stoul(input);
		}	while (index < 0 || index > amount);
	}
	printinfo_of_x(contact[index]);
}

void PhoneBook::printinfo(Contact contact, std::size_t i)
{
	std::string str;

	str = std::to_string(i);
	str.resize(10);
	std::cout << "|" << str << "|";
	str = contact.getFirstName();
	str.resize(10);
	std::cout << str << "|";
	str = contact.getLastName();
	str.resize(10);
	std::cout << str << "|";
	str = contact.getNickname();
	str.resize(10);
	std::cout << str << "|" << '\n';
}

void PhoneBook::printinfo_of_x(Contact contact)
{
	std::string str;

	str = contact.getFirstName();
	std::cout << "First name: " << str << '\n';
	str = contact.getLastName();
	std::cout << "Last name: " << str << '\n';
	str = contact.getNickname();
	std::cout << "Nickname: " << str << '\n';
	str = contact.getPhoneNb();
	std::cout << "Phone number: " << str << '\n';
	str = contact.getSecret();
	std::cout << "Darkest secret: " << str << '\n';
}
