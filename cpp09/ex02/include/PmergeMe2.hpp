/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:17 by dmaessen          #+#    #+#             */
/*   Updated: 2024/04/18 11:16:44 by dmaessen         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME2_HPP
#define PMERGEME2_HPP
#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <vector>
#include <exception>
#include <time.h>

class PmergeMe2
{
    private:
        std::deque<unsigned int> _deq;
        std::vector<unsigned int> _vec;

    public:
        PmergeMe2();
        ~PmergeMe2();
        PmergeMe2(const PmergeMe2 &src);
        PmergeMe2& operator=(const PmergeMe2 &src);
        
        int validateInput(char *argv);
        void printVec(void);
        void printDeque(void);

        int sort(int argc, char **argv);

        class NotIntException : public std::exception
        {
            public:
                const char* what() const throw();
        };    
    
        struct Pair {
            unsigned int value;
            size_t index;
            size_t smallParentIndex;
            size_t bigParentIndex;
            size_t depth;
        };

};

#endif