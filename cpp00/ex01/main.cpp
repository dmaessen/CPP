/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:27:36 by dmaessen          #+#    #+#             */
/*   Updated: 2023/11/09 15:27:37 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
