/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:58:32 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/10 15:21:39 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

//template <typename T> // probably not needed as we know the types
class Span
{
    private:
        unsigned int m_n; // size of container
        int m_added;
        std::vector<int> m_vec;
        Span(void); // needed?
    
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &src); // copy constructor
        Span& operator=(const Span &csrc); // assignment
    
        // int& operator[](int i) const;
        
        void addNumber(int i);

        int shortestSpan();
        int longestSpan(); // implement
        
        void addManyNumbers(); // implement this with a range of iterators

        class VectorFullException : public std::exception
        {
            virtual const char* what(void) const throw();
        };

        class NoSpanFoundException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
};

typedef std::vector<int>::const_iterator vectIter;

#endif