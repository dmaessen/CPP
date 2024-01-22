/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.cpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 13:45:48 by domi             ###   ########.fr       */
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
    // catch(const AForm::GradeTooHighException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too high, highest possible grade is 1.\n";
    // }
    // catch(const AForm::GradeTooLowException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too low, lowest possible grade is 150.\n";
    // }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Default constructor called on " << fname << "\n";
}

AForm::~AForm(void) {
    std::cout << "Destructor called on " << getFname() << "\n";
}

AForm::AForm(const AForm &copy) : m_fname(copy.m_fname), m_signgrade(copy.m_signgrade), m_execgrade(copy.m_execgrade) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

AForm& AForm::operator=(const AForm &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called\n";
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
    // if (grade > 0 && grade < 151)
    //     m_signgrade = (size_t)grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void AForm::setGradeE( int grade ) {
    // if (grade > 0 && grade < 151)
    //     m_execgrade = (size_t)grade;
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

// AForm::GradeTooHighException::GradeTooHighException(int value) {
//     m_value = value;
// }

// int AForm::GradeTooHighException::getValue( void ) const {
//     return m_value;
// }

// AForm::GradeTooLowException::GradeTooLowException(int value) {
//     m_value = value; 
// }

// int AForm::GradeTooLowException::getValue( void ) const {
//     return m_value;
// }

void AForm::sign(int grade) {
    if (grade <= getSigngrade() && grade != 0)
        m_docsigned = true;
    else
        throw GradeTooLowException();
}

void AForm::beSigned(const Bureaucrat &b) {
    try {
        sign(b.getGrade());
    }
    // catch(const AForm::GradeTooLowException e) {
    //     std::cerr << "This grade is too low, lowest possible grade is 150.\n";
    // }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

const char * AForm::GradeTooHighException::what() const throw()
{
	return ("Grade is invalid. This grade is too high, highest possible grade is 1.\n");
}

const char * AForm::GradeTooLowException::what() const throw()
{
	return ("Grade is invalid. This grade is too low, lowest possible grade is 150.\n");
}

const char * AForm::FormNotSignedException::what() const throw()
{
	return ("Form was not signed.\n");
}
