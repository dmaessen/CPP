/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:30:25 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Form.hpp"
#include <iostream>

Form::Form() : m_signgrade(0), m_execgrade(0) {
    return ;
}

Form::Form(const std::string fname, int signgrade, int execgrade) : m_fname(fname), m_signgrade(signgrade), m_execgrade(execgrade) {
    m_docsigned = false; // not signed
    try {
        setGradeS(signgrade);
        setGradeE(execgrade);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
    std::cout << "Default constructor called on " << fname << "\n";
}

Form::~Form(void) {
    std::cout << "Destructor called on " << getFname() << "\n";
}

Form::Form(const Form &copy) : m_fname(copy.m_fname), m_signgrade(copy.m_signgrade), m_execgrade(copy.m_execgrade) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Form& Form::operator=(const Form &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called\n";
    return (*this);
}

const std::string Form::getFname( void ) const {
    return m_fname;
}

bool Form::getDocsigned( void ) const {
    return m_docsigned;
}

int Form::getSigngrade( void ) const {
    return m_signgrade;
}

int Form::getExecgrade( void ) const {
    return m_execgrade;
}

void Form::setGradeS( int grade ) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Form::setGradeE( int grade ) {
    if (grade < 1)
        throw GradeTooHighException();
    if (grade > 150)
        throw GradeTooLowException();
}

void Form::beSigned(const Bureaucrat &b) {
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

const char * Form::GradeTooHighException::what() const throw() {
	return ("grade is invalid. This grade is too high, highest possible grade is 1.\n");
}

const char * Form::GradeTooLowException::what() const throw() {
	return ("grade is invalid. This grade is too low, lowest possible grade is 150.\n");
}
