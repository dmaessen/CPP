/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:55 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 22:58:25 by domi             ###   ########.fr       */
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

static std::string lowerFname(std::string fname) {
    std::string lowerStr;
    for (size_t i = 0; i < fname.size(); i++)
        lowerStr += tolower(fname[i]);
    return (lowerStr);
}

AForm* Intern::makeForm(std::string fname, std::string target) {
    AForm* f = NULL;
    std::string str = lowerFname(fname);
    
    try {
        if (str == "robotomy request" || str == "presidential pardon"
        || str == "shrubbery request")
        {
            char x = lowerFname(fname)[0];
            switch (x)
            {
                case 'r':
                {
                    f = new RobotomyRequestForm(target);
                    break;
                }
                case 'p': 
                {
                    f = new PresidentialPardonForm(target);
                    break;
                }
                case 's': 
                {
                    f = new ShrubberyCreationForm(target);
                    break;
                }
            }
            std::cout << "Intern creates " << f->getFname() << ".\n";
            return f;
        }
        else
            throw FormNotFoundException();
    }
    catch(const std::exception& e) {
        std::cout << "Intern couldn't make the form because the " << e.what();
        return (NULL);
    }
    return (NULL);
}

const char * Intern::FormNotFoundException::what() const throw() {
	return ("form was not found/existing.\n");
}