/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:55 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 15:12:23 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Intern.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <cstring>
#include <iostream>

class RobotomyRequestForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;

Intern::Intern(){
    std::cout << "Default constructor called on in Intern.\n";
}

Intern::~Intern(void) {
    std::cout << "Destructor called on in Intern.\n";
}

Intern::Intern(const Intern &copy) {
    std::cout << "Copy constructor called in Intern.\n";
    *this = copy;
}

Intern& Intern::operator=(const Intern &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called in Intern.\n";
    return (*this);
}

AForm* Intern::makeForm(std::string fname, std::string target) {
    std::string str;
    for (int i = 0; str[i] != ' ' || str[i] == '\0'; i++)
        str[i] = fname[i];
        
    try {
        if (str == "robotomy" || str == "presidential"
        || str == "shrubbery")
        {
            std::cout << "Intern creates " << fname << '\n';
            char x = str[0];
            switch (x)
            {
                case 'r':
                {
                    RobotomyRequestForm form(target);
                    return (form);
                    break;
                }
                case 'p': 
                {
                    PresidentialPardonForm form(target);
                    return (form);
                    break;
                }
                case 's': 
                {
                    ShrubberyCreationForm form(target);
                    return (form);
                    break;
                }
            }
        }
        else
            throw FormNotFoundException();
    }
    catch(const std::exception& e) {
        std::cout << "Intern couldn't make the form because the " << e.what();
    }
}

const char * Intern::FormNotFoundException::what() const throw() {
	return ("form was not found/existing.\n");
}