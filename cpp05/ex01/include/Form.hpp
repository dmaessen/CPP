/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Form.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 11:43:25 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/15 10:27:01 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FORM_HPP
#define FORM_HPP
#include "Bureaucrat.hpp"
#include <iostream>

class Form : public Bureaucrat // needed??
{
    private:
        const std::string m_fname;
        bool m_docsigned;
        const size_t m_signgrade;
        const size_t m_execgrade;

    public:
        Form(const std::string fname, bool docsigned);
        ~Form(void);
        Form(const Form &copy); // copy constructor
        Form& operator=(const Form &copy); // assignment

        const std::string getFname( void ) const;
        bool getDocsigned( void ) const;
        const size_t getSigngrade( void ) const;
        const size_t getExecgrade( void ) const;
        
        // beSigned(); to implement

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

std::ostream& operator<<(std::ostream &out, const Form &b);

#endif