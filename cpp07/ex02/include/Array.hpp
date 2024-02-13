/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Array.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 14:39:39 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 12:14:54 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ARRAY_HPP
#define ARRAY_HPP
#include <iostream>
#include <exception>

template <typename T>
class Array
{
    private:
        T* m_arr; // check if this needs to be allocated directly tho
        size_t m_size;
        
    public:
        Array(void);
        Array(unsigned int n);
        ~Array();
        Array(const Array &src); // copy constructor
        Array& operator=(const Array &csrc); // assignment

        T &operator[](size_t i) const;
        size_t size(void) const;

        class OutOfBoundException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
};

#include "Array.tpp"

template <typename T>
std::ostream	&operator<<(std::ostream &o, const Array<T> &src);


#endif