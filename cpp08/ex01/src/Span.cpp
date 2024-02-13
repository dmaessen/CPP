/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/13 11:30:52 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <limits>
#include <limits.h>
#include <algorithm>
#include <cmath>
#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <ctime>

Span::Span(void){
    std::cout << "Default constructor called\n";
}

Span::Span(unsigned int n) : m_n(n), m_added(0){
    std::cout << "Default constructor called\n";
}

Span::~Span(void){
    std::cout << "Destructor called on\n";
}

Span::Span(const Span &copy){
    *this = copy;
    std::cout << "Copy constructor called\n";
}

Span& Span::operator=(const Span &copy){
    if (this != &copy)
        *this = copy;
    std::cout << "Copy assignement operator called\n";
    return *this;
}

void Span::addNumber(int i) {
    if (m_n >= m_added)
    {
        m_vec.push_back(i);
        m_added++;
    }
    else
        throw VectorFullException();
}

const char * Span::VectorFullException::what() const throw() {
    return ("Impossible to add this int, exceeding the size of the vector.\n");
}

int Span::shortestSpan(void) {
    if (m_added < 2)
    {
        throw NoSpanFoundException();
        return -1;
    }
    int minDist = INT_MAX;
    int size = m_vec.size();
    for (int i = 0; i < size; i++) {
        for (int j = i + 1; j - 1 < size; j++) {
            int currentDist = abs(m_vec[i] - m_vec[j]);
            if (currentDist < minDist)
                minDist = currentDist;
        }
    }
    return minDist;
}

int Span::longestSpan(void) {
    if (m_added < 2)
    {
        throw NoSpanFoundException();
        return -1;
    }
    vectIter smallIter = std::min_element(m_vec.begin(), m_vec.end());
    vectIter bigIter = std::max_element(m_vec.begin(), m_vec.end());
    return abs(*bigIter - *smallIter);
}

const char * Span::NoSpanFoundException::what() const throw() {
    return ("No span found, you need to have at least 2 numbers in the vector.\n");
}

void Span::addNumbers(vectIter begin, vectIter end)
{
	if (std::distance(begin, end) + m_vec.size() > m_n + 1)
		throw VectorFullException();
    else {
        for (int i = 0; i + begin != end; i++)
        {
            m_vec.push_back(*(begin + i));
            m_added++;
        }
    }
}