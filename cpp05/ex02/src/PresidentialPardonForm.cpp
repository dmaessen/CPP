/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PresidentialPardonForm.cpp                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:24:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PresidentialPardonForm.hpp"
#include "../include/AForm.hpp"
#include <iostream>
#include <fstream>

PresidentialPardonForm::PresidentialPardonForm(std::string target) : AForm("PresidentialPardonForm", 25, 5), m_target(target){
    std::cout << "Default constructor called on " << m_target << " in PresidentialPardonForm.\n";
}

PresidentialPardonForm::~PresidentialPardonForm(void) {
    std::cout << "Destructor called on " << m_target << " in PresidentialPardonForm.\n";
}

PresidentialPardonForm::PresidentialPardonForm(const PresidentialPardonForm &copy) : AForm(copy.getFname(), copy.getSigngrade(), copy.getExecgrade()), m_target(copy.m_target){
    std::cout << "Copy constructor called in PresidentialPardonForm.\n";
    *this = copy;
}

PresidentialPardonForm& PresidentialPardonForm::operator=(const PresidentialPardonForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called in PresidentialPardonForm.\n";
    return (*this);
}

std::string PresidentialPardonForm::getTarget( void ) const {
	return m_target;
}

void PresidentialPardonForm::beExecuted(const Bureaucrat& executor) const {
	if (this->getDocsigned() == false)
		throw FormNotSignedException();
    else if (executor.getGrade() > this->getExecgrade())
		throw GradeTooLowException();
	else
	    std::cout << this->m_target << " has been pardoned by Zaphod Beeblebrox.\n";
}
