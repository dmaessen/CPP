/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:06:01 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/23 11:38:22 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include "Form.hpp"

class Form;

class Bureaucrat
{
    private:
        const std::string m_name;
        int m_grade;

    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat &copy); // copy constructor
        Bureaucrat& operator=(const Bureaucrat &copy); // assignment

        const std::string getName( void ) const;
        int getGrade( void ) const;
        void setGrade( int grade );
        
        void incrGrade( void ); 
        void decrGrade( void );

        void signForm(Form &f);

        class GradeTooHighException : public std::exception
        {
            virtual const char* what(void) const throw();
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif