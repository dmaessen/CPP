/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:36:33 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ShrubberyCreationForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

ShrubberyCreationForm::ShrubberyCreationForm(std::string target) : AForm("ShrubberyCreationForm", 145, 137), m_target(target){
    std::cout << "ShrubberyCreationForm Default constructor called on " << target << "\n";
	// if (getExecgrade() > 137)
    //     throw GradeTooLowException(getExecgrade());
	// else if (getSigngrade() > 145)
	// 	throw GradeTooLowException(getExecgrade());
}

ShrubberyCreationForm::~ShrubberyCreationForm(void) {
    std::cout << "ShrubberyCreationForm Destructor called on " << m_target << "\n";
}

ShrubberyCreationForm::ShrubberyCreationForm(const ShrubberyCreationForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "ShrubberyCreationForm Copy constructor called\n";
    *this = copy;
}

ShrubberyCreationForm& ShrubberyCreationForm::operator=(const ShrubberyCreationForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "ShrubberyCreationForm Copy assignment operator called\n";
    return (*this);
}

std::string ShrubberyCreationForm::getTarget( void ) const {
	return m_target;
}

void ShrubberyCreationForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	
	std::ofstream outfile;
	std::string str;
	str = "_shrubbery";
	outfile.open(m_target + str, std::ios::out);
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
	outfile << "			 |___|        " << "\n\n\n\n";
	
	// outfile << "          &&& &&  & &&" << '\n';
	// outfile << "      && &\/&\|& ()|/ @, &&" << '\n';
	// outfile << "      &\/(/&/&||/& /_/)_&/_&" << '\n';
	// outfile << "   &() &\/&|()|/&\/ '% & ()~" << '\n';
	// outfile << "  &_\_&&_\ |& |&&/&__%_/_& &&" << '\n';
	// outfile << "&&   && & &| &| /& & % ()& /&&" << '\n';
	// outfile << " ()&_---()&\&\|&&-&&--%---()~" << '\n';
	// outfile << "     &&     \|||" << "\n";
	// outfile << "             |||" << "\n";
	// outfile << "             |||" << "\n";
	// outfile << "             |||" << "\n";
	// outfile << "       , -=-~  .-^- _" << "\n";

	outfile.close();
}

