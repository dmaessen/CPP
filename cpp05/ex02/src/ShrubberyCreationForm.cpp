/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ShrubberyCreationForm.cpp                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:01:03 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), m_target(target){
    std::cout << "RobotomyRequestForm Default constructor called on " << target << "\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "RobotomyRequestForm Destructor called on " << m_target << "\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "RobotomyRequestForm Copy constructor called\n";
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "RobotomyRequestForm Copy assignment operator called\n";
    return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return m_target;
}

void RobotomyRequestForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	
	std::cout << "drilling noises...\n";
	std::srand(time(NULL));
	if (std::rand() % 2 == 0)
		std::cout << this->m_target << " has been robotomized successfully.\n";
	else
		std::cout << this->m_target << " robotomy failed.\n";
}

