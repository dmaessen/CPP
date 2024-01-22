/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:04:10 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), m_target(target){
    std::cout << "PresidentialPardonForm Default constructor called on " << target << "\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "PresidentialPardonForm Destructor called on " << m_target << "\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "PresidentialPardonForm Copy constructor called\n";
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "PresidentialPardonForm Copy assignment operator called\n";
    return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return m_target;
}

void PresidentialPardonForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
	if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	
	std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}