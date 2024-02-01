/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:39 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/01 16:45:12 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>
#include "Array.tpp"

template <typename T> // or class here??
class Array
{
    private:
        T* m_arr; // or T arr[] ??
        size_t m_size; // extra m_size to know in advance
        
    public:
        Array(void); // creates an empty arr
        Array(unsigned int n);// does this work?? //creates an arr of n elements
        ~Array();
        Array(const Array &copy); // copy constructor -- TO DO
        Array& operator=(const Array &copy); // assignment -- TO DO

        T &operator[](size_t i) const;
        size_t size(void) const;// returns the nb of elements in the arr

        class OutOfBoundException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
};

template <typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &src);


#endif