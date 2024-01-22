/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.cpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:58 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:25:15 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include <iostream>

Bureaucrat::Bureaucrat(const std::string name, int grade) : m_name(name) {
    std::cout << "Default constructor called on " << name << "\n";
    try {
        setGrade(grade);
    }
    // catch(const Bureaucrat::GradeTooHighException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too high, highest possible grade is 1.\n";
    // }
    // catch(const Bureaucrat::GradeTooLowException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too low, lowest possible grade is 150.\n";
    // }
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
    // catch(const Bureaucrat::GradeTooHighException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too high, highest possible grade is 1.\n";
    // }
    // catch(const Bureaucrat::GradeTooLowException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too low, lowest possible grade is 150.\n";
    // }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

void Bureaucrat::decrGrade( void ) {
    try {
        setGrade(m_grade + 1);
    }
    // catch(const Bureaucrat::GradeTooHighException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too high, highest possible grade is 1.\n";
    // }
    // catch(const Bureaucrat::GradeTooLowException e) {
    //     std::cerr << e.getValue() << " is invalid. This grade is too low, lowest possible grade is 150.\n";
    // }
    catch(const std::exception& e) {
        std::cerr << e.what() << '\n';
    }
}

std::ostream &operator<<(std::ostream &out, const Bureaucrat &b) {
    out << b.getName() << ", bureaucrat grade " << b.getGrade() << ".\n"; // <name>, bureaucrat grade <grade>.
    return out;
}

// Bureaucrat::GradeTooHighException::GradeTooHighException(int value) {
//     m_value = value;
// }

// int Bureaucrat::GradeTooHighException::getValue( void ) const {
//     return m_value;
// }

// Bureaucrat::GradeTooLowException::GradeTooLowException(int value) {
//     m_value = value; 
// }

// int Bureaucrat::GradeTooLowException::getValue( void ) const {
//     return m_value;
// }

const char * Bureaucrat::GradeTooHighException::what() const throw() {
    return ("Grade is invalid. This grade is too high, highest possible grade is 1.\n");
}

const char * Bureaucrat::GradeTooLowException::what() const throw() {
    return ("Grade is invalid. This grade is too low, lowest possible grade is 150.\n");
}

void Bureaucrat::signForm(AForm &f) {
    // if (f.getDocsigned() == true)
    //     std::cout << getName() << " signed " << f.getFname() << ".\n";  // <bureaucrat> signed <form>
    // else
    //     std::cout << getName() << " couldn't sign " << f.getFname() << " because its grade is too low.\n"; // <bureaucrat> couldn’t sign <form> because <reason>.

    try {
        f.beSigned(*this);
        std::cout << getName() << " signed " << f.getFname() << ".\n";  // <bureaucrat> signed <form>
    }
    catch(const std::exception& e) {
        std::cerr << getName() << " couldn't sign " << f.getFname() << " because " << e.what() << '\n';
    }
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


