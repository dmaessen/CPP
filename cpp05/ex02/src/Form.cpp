/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:28 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/19 11:37:15 by domi             ###   ########.fr       */
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
    catch(const Form::GradeTooHighException e) {
        std::cerr << e.getValue() << " is invalid. This grade is too high, highest possible grade is 1.\n";
    }
    catch(const Form::GradeTooLowException e) {
        std::cerr << e.getValue() << " is invalid. This grade is too low, lowest possible grade is 150.\n";
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
    // if (grade > 0 && grade < 151)
    //     m_signgrade = (size_t)grade;
    if (grade < 1)
        throw GradeTooHighException(grade);
    if (grade > 150)
        throw GradeTooLowException(grade);
}

void Form::setGradeE( int grade ) {
    // if (grade > 0 && grade < 151)
    //     m_execgrade = (size_t)grade;
    if (grade < 1)
        throw GradeTooHighException(grade);
    if (grade > 150)
        throw GradeTooLowException(grade);
}

Form::GradeTooHighException::GradeTooHighException(int value) {
    m_value = value;
}

int Form::GradeTooHighException::getValue( void ) const {
    return m_value;
}

Form::GradeTooLowException::GradeTooLowException(int value) {
    m_value = value; 
}

int Form::GradeTooLowException::getValue( void ) const {
    return m_value;
}

void Form::sign(int grade) {
    if (grade <= getSigngrade() && grade != 0)
        m_docsigned = true;
    else
        throw GradeTooLowException(grade);
}

void Form::beSigned(const Bureaucrat &b) {
    try {
        sign(b.getGrade());
    }
    catch(const Form::GradeTooLowException e) {
        std::cerr << "This grade is too low, lowest possible grade is 150.\n";
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}
