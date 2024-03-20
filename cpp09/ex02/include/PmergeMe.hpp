/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   PmergeMe.hpp                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dmaessen <dmaessen@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 13:41:21 by dmaessen          #+#    #+#             */
/*   Updated: 2024/03/20 15:02:57 by dmaessen         ###   ########.fr       */
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
        ~PmergeMe();
        PmergeMe(const PmergeMe &src);
        PmergeMe& operator=(const PmergeMe &src);
        
        int validateInput(char *argv);
        void printVec(void);
        void printDeque(void);

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
                    container[j] = container[j -1];
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
            T rightHalf(n1);
            T leftHalf(n2);
            for (int i = pos; i < q + 1; i++) // or not size + 1 myabe? +2??
                rightHalf[i] = container[i];
            int j = 0;
            for (int i = (q + 1); i < size + 1; i++) {
                leftHalf[j] = container[i];
                j++;
            }
            int rIndex = 0;
            int lIndex = 0;
            for (int i = 0; i < size - pos + 1; i++) {
                if (rIndex == n2){
                    container[i]= leftHalf[lIndex];
                    lIndex++;
                }
                else if (lIndex == n1){
                    container[i]= rightHalf[rIndex];
                    rIndex++;
                }
                else if (rightHalf[rIndex] > leftHalf[lIndex]) {
                    container[i] = leftHalf[lIndex];
                    lIndex++;
                }
                else {
                    container[i] = rightHalf[rIndex];
                    rIndex++;
                }
            }
        }
        
        template<typename T>
        void mergeinsertSort(T &container, int pos, int size)
        {
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