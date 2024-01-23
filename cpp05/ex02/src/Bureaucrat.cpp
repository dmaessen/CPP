/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:58 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:47:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name) {
    std::cout << "Default constructor called on " << name << "\n";
    try {
        m_grade = grade;
        setGrade(grade);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

Bureaucrat::~Bureaucrat(void) {
    std::cout << "Destructor called on " << getName() << "\n";
}

Bureaucrat::Bureaucrat(const Bureaucrat &copy) {
    std::cout << "Copy constructor called\n";
    *this = copy;
}

Bureaucrat& Bureaucrat::operator=(const Bureaucrat &copy) {
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignment operator called\n";
    return (*this);
}

const std::string Bureaucrat::getName( void ) const {
    return m_name;
}

int Bureaucrat::getGrade( void ) const {
    return m_grade;
}

void Bureaucrat::setGrade( int grade) {
    if (grade > 0 && grade < 151)
        m_grade = grade;
    else if (grade < 1)
        throw GradeTooHighException();
    else if (grade > 150)
        throw GradeTooLowException();
}
        
void Bureaucrat::incrGrade( void ) {
    try {
        setGrade(m_grade - 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::decrGrade( void ) {
    try {
        setGrade(m_grade + 1);
    }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n";
    return out;
}

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is invalid. This grade is too high, highest possible grade is 1.\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is invalid. This grade is too low, lowest possible grade is 150.\n");
}

void Bureaucrat::signForm(AForm &f) {
    f.beSigned(*this);
}

void Bureaucrat::executeForm(AForm const & f) const {
    try {
        f.beExecuted(*this);
        std::cout << getName() << " executed " << f.getFname() << ".\n";
    }
    catch(const std::exception& e) {
        std::cout << getName() << " cannot execute " << f.getFname() << " because " << e.what() << '\n';
    }
}
