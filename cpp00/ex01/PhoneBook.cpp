/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PhoneBook.cpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:40 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/13 12:15:37 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Contact.hpp"
#include "PhoneBook.hpp"
#include <iostream>
#include <string>
#include <string.h>
#include <sstream>
#include <stdio.h>
#include <iomanip>

void PhoneBook::init()
{
	m_count_contacts = 0;
}

PhoneBook::PhoneBook() 
{

}

PhoneBook::~PhoneBook()
{

}

void PhoneBook::cmd_add()
{
	Contact newcontact;
	
	newcontact = getInfo();
	contact[m_count_contacts % 8] = newcontact;
	m_count_contacts += 1;
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
		printinfo(contact[i], i);
	std::cout << "Please enter an index: ";
	std::getline(std::cin, input);
	try 
	{
		index = std::stoul(input);
	}
	catch (std::invalid_argument const& ex)
	{
		std::cout << "Error in: " << ex.what() << '\n';
	}
	if (index == 0 && amount == 1)
		printinfo_of_x(contact[0]);
	if (index < 0 || index > amount - 1)
	{
		std::cout << "Invalid index, try again.\n";
		do {
			std::getline(std::cin, input);
			index = std::stoul(input);
		}	while (index < 0 || index > amount - 1);
	}
	printinfo_of_x(contact[index]);
}

void PhoneBook::printinfo(Contact contact, std::size_t i)
{
	std::string str;

	std::cout << "|";
	str = std::to_string(i);
	if (str.size() > 10)
		str[9] = '.';
	if (str.size()  < 10)
		std::cout << std::right << std::setw(10 - str.size()) << " ";
	str.resize(10);
	std::cout << std::right << str << "|";
	
	str = contact.getFirstName();
	if (str.size() > 10)
		str[9] = '.';
	if (str.size() < 10)
		std::cout << std::right << std::setw(10 - str.size()) << " ";
	str.resize(10);
	std::cout << std::right << str << "|";
	
	str = contact.getLastName();
	if (str.size() > 10)
		str[9] = '.';
	if (str.size() < 10)
		std::cout << std::right << std::setw(10 - str.size()) << " ";
	str.resize(10);
	std::cout << std::right << str << "|";
	
	str = contact.getNickname();
	if (str.size() > 1)
		str[9] = '.';
	if (str.size() < 10)
		std::cout << std::right << std::setw(10 - str.size()) << " ";
	str.resize(10);
	std::cout << std::right << str << "|" << '\n';
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
