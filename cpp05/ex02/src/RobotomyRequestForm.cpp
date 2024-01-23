/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   RobotomyRequestForm.cpp                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 10:46:15 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/RobotomyRequestForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

RobotomyRequestForm::RobotomyRequestForm(std::string target) : AForm("RobotomyRequestForm", 72, 45), m_target(target){
    std::cout << "Default constructor called on " << target << " in RobotomyRequestForm.\n";
}

RobotomyRequestForm::~RobotomyRequestForm(void) {
    std::cout << "Destructor called on " << m_target << " in RobotomyRequestForm.\n";
}

RobotomyRequestForm::RobotomyRequestForm(const RobotomyRequestForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "Copy constructor called in RobotomyRequestForm.\n";
    *this = copy;
}

RobotomyRequestForm& RobotomyRequestForm::operator=(const RobotomyRequestForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called in RobotomyRequestForm.\n";
    return (*this);
}

std::string RobotomyRequestForm::getTarget( void ) const {
	return m_target;
}

void RobotomyRequestForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
	else if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	else {
		std::cout << "drilling noises...\n";
		std::srand(time(NULL));
		if (std::rand() % 2 == 0)
			std::cout << this->m_target << " has been robotomized successfully.\n";
		else
			std::cout << this->m_target << " robotomy failed.\n";
	}
}
