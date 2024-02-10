/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/10 15:22:33 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/Span.hpp"
#include <limits>
#include <algorithm>
#include <cmath>
#include <vector>

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

// int& Span::operator[](int i) const {
// 	if (i >= m_n) {
//         std::cout << "Index out of bound, exiting.\n";
//         exit(0); // allowed
//     }
// 	return m_data[i];
// }

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
        return -1; // correct??
    }
    int [small, big] = std::minmax_element(m_vec.begin(), m_vec.end()); // or (begin(m_vec), end(m_vec))
    int minDist = INT_MAX;
    for (int i = 0; i < m_vec.size(); i++) {
        for (int j = i + 1; i < m_vec.size(); j++) {
            if ((small == m_vec[i] && big == m_vec[j]
            || big == m_vec[i] && small == m_vec[j])
            && minDist > abs(i - j))
                minDist = abs(i -j);
        }
    }
    if (minDist > m_vec.size()) // this is weird no??
        return -1;
    return minDist;
}

int Span::longestSpan(void) {
    if (m_added < 2)
    {
        throw NoSpanFoundException();
        return -1; // correct??
    }
    vectIter smallIter = std::min_element(m_vec.begin(), m_vec.end()); // type def veciter like said in the subject
    vectIter bigIter = std::max_element(m_vec.begin(), m_vec.end());
    //int maxDist = abs(big - small); // is abs needed ?? and if its 0
    return abs(bigIter - smallIter); // or pointer to it?
}

const char * Span::NoSpanFoundException::what() const throw() {
    return ("No span found, you need to have at least 2 numbers in the vector.\n");
}
