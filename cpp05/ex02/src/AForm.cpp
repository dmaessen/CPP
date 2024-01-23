/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:27:55 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/AForm.hpp"
#include <iostream>

AForm::AForm() : m_signgrade(0), m_execgrade(0) {
    return ;
}

AForm::AForm(const std::string fname, int signgrade, int execgrade) : m_fname(fname), m_signgrade(signgrade), m_execgrade(execgrade) {
    m_docsigned = false; // not signed
    try {
        setGradeS(signgrade);
        setGradeE(execgrade);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Default constructor called on " << fname << " in AForm.\n";
}

AForm::~AForm(void) {
    std::cout << "Destructor called on " << getFname() << " in AForm.\n";
}

AForm::AForm(const AForm &copy) : m_fname(copy.m_fname), m_signgrade(copy.m_signgrade), m_execgrade(copy.m_execgrade) {
    std::cout << "Copy constructor called in AForm.\n";
    *this = copy;
}

AForm& AForm::operator=(const AForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called in AForm.\n";
    return (*this);
}

const std::string AForm::getFname( void ) const {
    return m_fname;
}

bool AForm::getDocsigned( void ) const {
    return m_docsigned;
}

int AForm::getSigngrade( void ) const {
    return m_signgrade;
}

int AForm::getExecgrade( void ) const {
    return m_execgrade;
}

void AForm::setGradeS( int grade ) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void AForm::setGradeE( int grade ) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &b) {
    try {
        if (b.getGrade() <= getSigngrade() && b.getGrade() != 0)
        {
            m_docsigned = true;
            std::cout << b.getName() << " signed " << getFname() << ".\n";
        }
        else
            throw GradeTooLowException();
    }
    catch(const std::exception& e) {
        std::cerr << b.getName() << " couldn't sign " << getFname() << " because " << e.what();
    }
}

const char * AForm::GradeTooHighException::what() const throw() {
	return ("grade is invalid. This grade is too high, highest possible grade is 1.\n");
}

const char * AForm::GradeTooLowException::what() const throw() {
	return ("grade is invalid. This grade is too low, lowest possible grade is 150.\n");
}

const char * AForm::FormNotSignedException::what() const throw() {
	return ("form was not signed.\n");
}
