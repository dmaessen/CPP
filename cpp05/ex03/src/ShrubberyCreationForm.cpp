/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:23:50 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target){
    std::cout << "Default constructor called on " << target << " in ShrubberyCreationForm.\n";
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "Destructor called on " << m_target << " in ShrubberyCreationForm.\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "Copy constructor called in ShrubberyCreationForm.\n";
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called in ShrubberyCreationForm.\n";
    return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return m_target;
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	else {
		std::string name = this->m_target + "_shrubbery";
		std::ofstream outfile(name.c_str());
		if (!outfile.is_open())
			std::cout << "Error: opening outfile\n";

		outfile << " 			   .          " << "\n";
		outfile << "			__/ |__       " << "\n";
		outfile << "			|     /       " << "\n";
		outfile << "			 .'o'.       " << "\n";
		outfile << "			 .o.'.        " << "\n";
		outfile << "			.'.'o'.       " << "\n";
		outfile << "		   o'.o.'.o.      " << "\n";
		outfile << "		  .'.o.'.'.o.     " << "\n";
		outfile << "		 .o.'.o.'.o.'.    " << "\n";
		outfile << "		    [_____]       " << "\n";
		outfile << "			 |___|        " << "\n";

		outfile.close();
	}
}
