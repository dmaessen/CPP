/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:06:01 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 14:24:00 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>
#include "AForm.hpp"

class AForm; // needed ??

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

        void signForm(AForm &f);
        void executeForm(AForm const & f) const;

        class GradeTooHighException : public std::exception
        {
            virtual const char* what(void) const throw();
            // private:
            //     int m_value;
            
            // public:
            //     GradeTooHighException(int value);
            //     int getValue( void ) const;
        };

        class GradeTooLowException : public std::exception
        {
            virtual const char* what(void) const throw();
            // private:
            //     int m_value;
            
            // public:
            //     GradeTooLowException(int value);
            //     int getValue( void ) const;
        };
        
};

std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif