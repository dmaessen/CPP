/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:25 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/19 11:33:42 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Bureaucrat;

class Form
{
    private:
        const std::string m_fname;
        bool m_docsigned;
        const int m_signgrade;
        const int m_execgrade;

    public:
        Form(void);
        Form(const std::string fname, int signgrade, int execgrade);
        ~Form(void);
        Form(const Form &copy); // copy constructor
        Form& operator=(const Form &copy); // assignment

        const std::string getFname( void ) const;
        bool getDocsigned( void ) const;
        int getSigngrade( void ) const;
        int getExecgrade( void ) const;
        
        void setGradeE( int grade );
        void setGradeS( int grade );
        
        void beSigned(const Bureaucrat &b); // to implement
        
        void sign(int grade);

        class GradeTooHighException
            {
                private:
                    int m_value;
                
                public:
                    GradeTooHighException(int value);
                    int getValue( void ) const;
            };

            class GradeTooLowException
            {
                private:
                    int m_value;
                
                public:
                    GradeTooLowException(int value);
                    int getValue( void ) const;
            };
        
};

#endif