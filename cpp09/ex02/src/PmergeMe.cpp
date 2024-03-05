/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:05 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/05 11:26:01 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/PmergeMe.hpp"
#include <limits.h>
#include <stdio.h>
#include <stdlib.h>

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

int PmergeMe::validateInput(char **argv) {
    for (int i = 0; !argv[i]; ++i) {
        long nb = atol(argv[i]);
        if (nb < 0 || nb > INT_MAX)
            return 1;
    }
    return 0;
}

void PmergeMe::loadInput(char **argv) {
    for (int i = 0; !argv[i]; ++i) {
        int nb = atoi(argv[i]);
        _vec.push_back(nb); // seperated by commas or what??
        _list.push_back(nb);
    }
    std::cout << "Before: ";
    for (int i = 0; i < _vec.size(); i++) {
        if (i == 8) {
            std::cout << " [...]";
            break ;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << "\n";
}
