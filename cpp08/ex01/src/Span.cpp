/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Span.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 11:10:38 by dmaessen          #+#    #+#             */
/*   Updated: 2024/02/12 16:25:15 by dmaessen         ###   ########.fr       */
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

void Span::addManyNumbers(void) {
    std::vector<int> copy(1);
    // std::srand(time(NULL));
    std::srand(static_cast<unsigned>(std::time(nullptr)));
    for (size_t size = 0; size < m_n; size++)
    {
        for (int &nb : copy) // i have doubts (or auto instead of int??)
        {
            nb = std::rand() % (101 -50) + 50;
            m_vec.push_back(nb);
        }
        
    }
    
    // for (int &nb : m_vec) // i have doubts (or auto instead of int??)
    // {
    //     nb = std::rand() % (101 -50) + 50;
    //     // m_vec.push_back(nb);
    // }
    
    m_added = m_n; // not sure if needed but well
    for (int i = 0; i < 20; i++)
        std::cout << copy[i] << '\n';
    std::cout << m_added <<  " || size " << copy.size() << '\n';
    //for(auto a : array3){
    //     array3.push_back(rand() % (101 -50) + 50);
    // }
}