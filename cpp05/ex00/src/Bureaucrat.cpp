/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:58 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/13 15:45:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name) {
    // check if name empty??
    // implement exceptions
        // Bureaucrat::GradeTooHighException
        // Bureaucrat::GradeTooLowException
    std::cout << "Default constructor called on " << name << "\n";
    try
    {
        if (grade < 1 || grade > 150)
            throw MyException();
        else
            m_grade = (size_t)grade; // is all goes well
    }
    catch(const MyException& e)
    {
        if (m_grade < 1)
            std::cerr << e.GradeTooHighException() << '\n';
        if (m_grade > 150)
            std::cerr << e.GradeTooLowException() << '\n';
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

size_t Bureaucrat::getGrade( void ) const {
    return m_grade;
}

void Bureaucrat::setGrade( int grade) {
    if (grade )
}
        
void Bureaucrat::incrGrade( void ) {
    try
    {
        if ((m_grade - 1) < 1 || (m_grade - 1) > 150)
            throw MyException();
        else
            m_grade -= 1;
    }
    catch(const MyException& e)
    {
        if ((m_grade - 1) < 1)
            std::cerr << e.GradeTooHighException() << '\n';
        if ((m_grade - 1) > 150)
            std::cerr << e.GradeTooLowException() << '\n';
    }
}

void Bureaucrat::decrGrade( void ) {
    try
    {
        if ((m_grade + 1) < 1 || (m_grade + 1) > 150)
            throw MyException();
        else
            m_grade += 1;
    }
    catch(const MyException& e)
    {
        if ((m_grade + 1) < 1)
            std::cerr << e.GradeTooHighException() << '\n';
        if ((m_grade + 1) > 150)
            std::cerr << e.GradeTooLowException() << '\n';
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n"; // <name>, bureaucrat grade <grade>.
    return out;
}

Bureaucrat::GradeTooHighException::GradeTooHighException(int value) {
    m_value = value;
}

int Bureaucrat::GradeTooHighException::getValue( void ) const {
    return m_value;
}

Bureaucrat::GradeTooLowException::GradeTooLowException(int value) {
    m_value = value; 
}

int Bureaucrat::GradeTooLowException::getValue( void ) const {
    return m_value;
}

// int Bureaucrat::GradeTooHighException(std::string msg) {
//     std::cout << msg;
//     return 1;
// }

// int Bureaucrat::GradeTooLowException(std::string msg) {
//     std::cout << msg;
//     return 1;
// }

// const char* MyException::GradeTooHighException() const {
//     return "Grade is too high, highest possible grade is 1.";
// }

// const char* MyException::GradeTooLowException() const {
//     return "Grade is too low, lowest possible grade is 150.";
// }