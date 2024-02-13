/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:58:32 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 11:31:56 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPAN_HPP
#define SPAN_HPP
#include <iostream>
#include <vector>
#include <algorithm>

typedef std::vector<int>::const_iterator vectIter;

class Span
{
    private:
        unsigned int m_n; // size of container
        unsigned int m_added;
        std::vector<int> m_vec;
        Span(void);
    
    public:
        Span(unsigned int n);
        ~Span();
        Span(const Span &src); // copy constructor
        Span& operator=(const Span &csrc); // assignment
    
        
        void addNumber(int i);
        void addNumbers(vectIter begin, vectIter end);

        int shortestSpan();
        int longestSpan();

        class VectorFullException : public std::exception
        {
            virtual const char* what(void) const throw();
        };

        class NoSpanFoundException : public std::exception
        {
            virtual const char* what(void) const throw();
        };
};


#endif