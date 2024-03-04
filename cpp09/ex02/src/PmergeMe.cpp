/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:05 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/04 14:57:27 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"

PmergeMe::PmergeMe(void) {
    // std::cout << "Default constructor called\n";
}

PmergeMe::~PmergeMe(){
    // std::cout << "Destructor called\n";
}

PmergeMe::PmergeMe(const PmergeMe &src) {
    // std::cout << "Copy constructor called\n";
    *this = src;
}

PmergeMe& PmergeMe::operator=(const PmergeMe &src) {
    //std::cout << "Copy assignment operator called\n";
     if (this != &src)
        *this = src;
    return (*this);
}

