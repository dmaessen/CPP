/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Intern.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/05 13:53:53 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/05 15:11:08 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INTERN_HPP
#define INTERN_HPP
#include <iostream>

class Bureaucrat;
class AForm;
class RobotomyRequestForm;
class ShrubberyCreationForm;
class PresidentialPardonForm;

class Intern 
{
    private:

    public:
        Intern(void);
        ~Intern(void);
        Intern(const Intern &copy); // copy constructor
        Intern& operator=(const Intern &copy); // assignment

        AForm* makeForm(std::string fname, std::string target);

        class FormNotFoundException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
    
};
#endif