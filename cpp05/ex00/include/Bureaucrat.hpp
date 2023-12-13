/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Bureaucrat.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/13 10:06:01 by dmaessen          #+#    #+#             */
/*   Updated: 2023/12/13 15:50:01 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUREAUCRAT_HPP
#define BUREAUCRAT_HPP
#include <iostream>
#include <stdexcept>

class Bureaucrat
{
    private:
        const std::string m_name;
        size_t m_grade;

    public:
        Bureaucrat(const std::string name, int grade);
        ~Bureaucrat(void);
        Bureaucrat(const Bureaucrat &copy); // copy constructor
        Bureaucrat& operator=(const Bureaucrat &copy); // assignment

        const std::string getName( void ) const;
        size_t getGrade( void ) const;
        void setGrade( int grade );
        
        void incrGrade( void ); 
        void decrGrade( void );

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
        // int GradeTooHighException(std::string msg);
        // int GradeTooLowException(std::string msg);
        
};

// class Bureaucrat
// {
//     private:
//         const std::string m_name;
//         size_t m_grade;

//     public:
//         Bureaucrat(const std::string name, int grade);
//         ~Bureaucrat(void);
//         Bureaucrat(const Bureaucrat &copy); // copy constructor
//         Bureaucrat& operator=(const Bureaucrat &copy); // assignment

//         const std::string getName( void ) const;
//         size_t getGrade( void ) const;
        
//         void incrGrade( void ); 
//         void decrGrade( void );

//         int GradeTooHighException(std::string msg);
//         int GradeTooLowException(std::string msg);
        
// };

// class MyException : public std::exception
// {
//     // private:
//     //     std::string m_msg;
        
//     public:
//         virtual const char* GradeTooHighException() const;
//         virtual const char* GradeTooLowException() const;
//         // GradeTooHighException(std::string msg);
//         // ~GradeTooHighException(void);
//         // std::string getMsg( void ) const;
// };


std::ostream& operator<<(std::ostream &out, const Bureaucrat &b);

#endif