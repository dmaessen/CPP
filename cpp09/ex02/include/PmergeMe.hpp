/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/13 16:08:23 by dmaessen         ###   ########.fr       */
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

class PmergeMe
{
    private:
        std::deque<int> _deq;
        std::vector<int> _vec;

    public:
        PmergeMe();
        ~PmergeMe(); // virtual??
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        
        int validateInput(char *argv);
        void printVec(void);
        void printDeque(void);

        //void sort(std::string const &input);
        int sort(int argc, char **argv);
        
        class NotIntException : public std::exception
        {
            public:
                const char* what() const throw();
        };
    
    template<typename T>
    void insertionSort(T &container, int l, int q)
    {
        for (int i = l; i < q; i++) {
            int tmp = container[i + 1];
            int j = i + 1;
            while (j > l && container[j - 1] > tmp) {
                container[j] = container[j -1]; // does this work for vectors?? deque??
                j--;
            }
            container[j] = tmp;
        }
    }

    template<typename T>
    void mergeSort(T& container, int pos, int q, int size)
    {
        int n1 = q - pos + 1;
        int n2 = size - q;
        T halfright; // am i right? or wih a size[]
        T halfleft;
        for (int i = pos; i < q + 1; i++) // or not size + 1 myabe? +2??
            halfright[i] = container[i];
        int j = 0;
        for (int i = (q + 1); i < size + 1; i++) {
            halfleft[j] = container[i];
            j++;
        }
        int rIndex = 0;
        int lIndex = 0;
        for (int i = 0; i < size - pos + 1; i++) {
            if (rIndex == n2){
                container[i]= halfleft[lIndex];
                lIndex++;
            }
            else if (lIndex == n1){
                container[i]= halfright[rIndex];
                rIndex++;
            }
            else if (halfright[rIndex] > halfleft[lIndex]) {
                container[i] = halfleft[lIndex];
                lIndex++;
            }
            else {
                container[i] = halfright[rIndex];
                rIndex++;
            }
        }
    }
    
    template<typename T>
	//void mergeinsertSort(T &container, int l, int r, int k) // l = 0 // r = .size() -1 // k = 100
    void mergeinsertSort(T &container, int pos, int size)
    {
        //pourquoi k = 100 du coup??
        int k = size;
        // donner des noms qui ont plus de sens, jui perdue
        if (size - pos > k) {
            int q = (pos + size) / 2;
            mergeinsertSort(container, pos, q);
            mergeinsertSort(container, q + 1, size);
            mergeSort(container, pos, q, size);
        }
        else
            insertionSort(container, pos, size);
    }
};

#endif