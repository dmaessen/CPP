/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:55 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:40:07 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include <iostream>

int main(void) {
    Bureaucrat b("Alice", 2);
    Bureaucrat b2("John", 151);
    
    std::cout << '\n' << b << "[incrementing] " << '\n';
    b.incrGrade();
    std::cout << b << '\n';
    std::cout << b << "[incrementing] " << '\n';
    b.incrGrade();
    std::cout << b << '\n';
    std::cout << b << "[decrementing] " << '\n';
    b.decrGrade();
    std::cout << b << '\n';

    std::cout << "----------------\n";
    ShrubberyCreationForm f("Shrubbery-taxes");
    b.signForm(f);
    b.executeForm(f);
    b2.signForm(f);
    b2.executeForm(f);

    std::cout << "----------------\n";
    RobotomyRequestForm f2("Robotomy-taxes");
    b.signForm(f2);
    b.executeForm(f2);
    b2.signForm(f2);
    b2.executeForm(f2);

    std::cout << "----------------\n";
    PresidentialPardonForm f3("Presidential-taxes");
    b.signForm(f3);
    b.executeForm(f3);
    b2.signForm(f3);
    b2.executeForm(f3);
    
    return 0;
}

// John is still able to sign/exec even tho the error of grade too low is give.. look into that