/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:05:55 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 22:46:50 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Bureaucrat.hpp"
#include "../include/AForm.hpp"
#include "../include/ShrubberyCreationForm.hpp"
#include "../include/RobotomyRequestForm.hpp"
#include "../include/PresidentialPardonForm.hpp"
#include "../include/Intern.hpp"
#include <iostream>

int main(void) {
    Bureaucrat b("Alice", 2);
    Bureaucrat b2("John", 140);
    
    std::cout << "----------------\n";
    Intern	i;
	AForm*	f = i.makeForm("Shrubbery request", "taxes");
    b.signForm(*f);
    b.executeForm(*f);
    b2.signForm(*f);
    b2.executeForm(*f);
    delete f;

    std::cout << "----------------\n";
    AForm*	f2 = i.makeForm("robotomy request", "taxes");
    b.signForm(*f2);
    b.executeForm(*f2);
    b2.signForm(*f2);
    b2.executeForm(*f2);
    delete f2;

    std::cout << "----------------\n";
    AForm*	f3 = i.makeForm("presidential pardon", "taxes");
    b.signForm(*f3);
    b.executeForm(*f3);
    b2.signForm(*f3);
    b2.executeForm(*f3);
    delete f3;
    
    return 0;
}
