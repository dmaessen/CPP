/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   AForm.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:25 by dmaessen          #+#    #+#             */
/*   Updated: 2024/01/22 13:40:09 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef AFORM_HPP
#define AFORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class AForm
{
    private:
        const std::string m_fname;
        bool m_docsigned;
        const int m_signgrade;
        const int m_execgrade;

    public:
        AForm(void);
        AForm(const std::string fname, int signgrade, int execgrade);
        virtual ~AForm(void);
        AForm(const AForm &copy); // copy constructor
        AForm& operator=(const AForm &copy); // assignment

        const std::string getFname( void ) const;
        bool getDocsigned( void ) const;
        int getSigngrade( void ) const;
        int getExecgrade( void ) const;
        
        void setGradeE( int grade );
        void setGradeS( int grade );
        
        void beSigned(const Bureaucrat &b);
        virtual void beExecuted(const Bureaucrat& executor) const = 0;
        
        void sign(int grade); // or another one??

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

            class FormNotSignedException : public std::exception
            {
                virtual const char* what(void) const throw();
            };
        
};

#endif