/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:05 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/13 10:55:26 by domi             ###   ########.fr       */
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

int PmergeMe::validateInput(char *argv) {
    std::string str = argv;
    if (str.length() > 10)
        return 1;
    long nb = stol(argv);
    if (nb < 0 || nb > INT_MAX)
        return 1;
    return 0;
}

void PmergeMe::printInput(void) {
    // for (int i = 0; !input[i]; ++i) {
    //     int nb = atoi(input[i]);
    //     _vec.push_back(nb); // seperated by commas or what??
    //     _list.push_back(nb);
    // }
    
    for (int i = 0; i < _vec.size(); i++) {
        if (i == 8) {
            std::cout << " [...]";
            break ;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << "\n";
}

int PmergeMe::sort(int argc, char **argv) {
    try {
        int nb;
        for (int i = 1; argv[i]; i++) {
            if (!validateInput(argv[i])) {
                throw NotIntException();
                break ;
            }
            std::istringstream(argv[i]) >> nb;
            _vec.push_back(nb); // seperated by commas or what??
            _deq.push_back(nb);
        }
    }
    catch(NotIntException &e) {
        std::cout << e.what();
        return 1;
    }
    // then function to print
    std::cout << "Before: "; // so to reuse the next function
    printInput();
    clock_t start = clock();
    // mergeinsertSort(); // to write
    clock_t end = clock();
    double t = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
    printInput();
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << t << " ms\n";
}

const char* PmergeMe::NotIntException::what() const throw() {
    return ("Error: invalid input\n");
}
