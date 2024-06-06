/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: domi <domi@student.42.fr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/18 10:54:17 by dmaessen          #+#    #+#             */
/*   Updated: 2024/06/06 15:24:36 by domi             ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PMERGEME_HPP
#define PMERGEME_HPP
#include <iostream>
#include <sstream>
#include <list>
#include <deque>
#include <vector>
#include <exception>
#include <time.h>
#include <algorithm>

class PmergeMe
{
    private:
        std::deque<unsigned int> _deq;
        std::vector<unsigned int> _vec;

    public:
        PmergeMe();
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        
        int validateInput(char *argv);
        void printVec(void);
        void printDeque(void);

        int start(int argc, char **argv);
        void sort(std::vector<unsigned int> &arr);
	    void sort(std::deque<unsigned int> &arr);

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
        
        void mergeinsertionSort(std::vector<Pair> &X, std::vector<Pair> &S, std::vector<Pair> &pairs, size_t depth);
	    bool insertionSort(std::vector<Pair> &S, size_t subsequenceLen, Pair &pair);

	    void mergeinsertionSort(std::deque<Pair> &X, std::deque<Pair> &S, std::deque<Pair> &pairs, size_t depth);
	    bool insertionSort(std::deque<Pair> &S, size_t subsequenceLen, Pair &pair);

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