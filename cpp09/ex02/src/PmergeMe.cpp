/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.cpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:15 by dmaessen          #+#    #+#             */
/*   Updated: 2024/06/06 15:26:24 by domi             ###   ########.fr       */
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
    long nb = atol(argv);
    if (nb < 0 || nb > INT_MAX)
        return 1;
    return 0;
}

void PmergeMe::printVec(void) {
    for (size_t i = 0; i < _vec.size(); i++) {
        if (i == 8) {
            std::cout << " [...]";
            break ;
        }
        std::cout << _vec[i] << " ";
    }
    std::cout << "\n";
}

void PmergeMe::printDeque(void){
    for (size_t i = 0; i < _deq.size(); i++) {
        if (i == 8) {
            std::cout << " [...]";
            break ;
        }
        std::cout << _deq[i] << " ";
    }
    std::cout << "\n";
}

int PmergeMe::start(int argc, char **argv) {
    try {
        int nb;
        for (int i = 1; argv[i]; i++) {
            if (validateInput(argv[i])) {
                throw NotIntException();
                break ;
            }
            std::istringstream(argv[i]) >> nb;
            _vec.push_back(nb);
            _deq.push_back(nb);
        }
    }
    catch(NotIntException &e) {
        std::cout << e.what();
        return 1;
    }

    std::cout << "Before: ";
    printVec();
    
    //VECTOR
    clock_t start = clock();
    // mergeinsertSort(_vec, 0, _vec.size() - 1);
    sort(_vec);
    clock_t end = clock();
    double t = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
    printVec();
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::vector : " << t << " ms\n";

    //DEQUE
    start = clock();
    // mergeinsertSort(_deq, 0, _deq.size() - 1);
    sort(_deq);
    end = clock();
    t = double(end - start) / CLOCKS_PER_SEC * 1000;
	std::cout << "After: ";
    printDeque();
    std::cout << "Time to process a range of " << argc - 1 << " elements with std::deque : " << t << " ms\n";

    return 0;
}

const char* PmergeMe::NotIntException::what() const throw() {
    return ("Error: invalid input\n");
}




