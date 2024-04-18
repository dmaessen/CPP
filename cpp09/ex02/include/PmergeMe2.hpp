/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe2.hpp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:17 by dmaessen          #+#    #+#             */
/*   Updated: 2024/04/18 11:47:01 by dmaessen         ###   ########.fr       */
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

        int start(int argc, char **argv);

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

        template<typename T>
        void sort(T &container, int pos, int size)
        {
            std::vector<Pair> origin;
            std::vector<Pair> pairs;
            
            for (size_t i = 0; i < container.size(); i++)
            {
                unsigned int value = container[i];
                Pair pair = {
                    .value = value,
                    .index = pairs.size(),
                    .smallParentIndex = SIZE_MAX, // indicates value being uninitialised
                    .bigParentIndex = SIZE_MAX,
                    .depth = 0,
                };
                origin.push_back(pair);
                pairs.push_back(pair);
            }
            std::vector<Pair> res;
            mergeInsertSort(origin, res, pairs, 1); // 1 is the dpeth here
            transferBack(res, container);
        }
};

#endif